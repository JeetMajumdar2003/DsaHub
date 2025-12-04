function normalise(value) {
  return value.toLowerCase();
}

export function filterTree(nodes, query) {
  if (!query) {
    return structuredClone(nodes);
  }

  const needle = normalise(query);

  function traverse(node) {
    const name = normalise(node.displayName ?? node.name ?? '');
    const isMatch = name.includes(needle);
    if (!node.children || node.children.length === 0) {
      return isMatch ? { ...node, isMatch } : null;
    }

    const mappedChildren = node.children
      .map(traverse)
      .filter((child) => child !== null);

    if (isMatch) {
      // If the directory itself matches the query, we want to preserve all of its children in the result,
      // not just the ones that matched the query. However, if any child also matched (and was mapped),
      // we replace the original child with its mapped version (which may include isMatch or filtered descendants).
      // This ensures that when a directory matches, its full subtree is shown, but with any matching children
      // properly annotated. This differs from the case where only children match, in which case we only include
      // the filtered/mapped children.
      const replacementMap = new Map(mappedChildren.map((child) => [child.path, child]));
      const fullChildren = node.children.map((child) => replacementMap.get(child.path) ?? structuredClone(child));
      return {
        ...node,
        isMatch,
        children: fullChildren
      };
    }

    if (mappedChildren.length > 0) {
      return {
        ...node,
        isMatch,
        children: mappedChildren
      };
    }

    return null;
  }

  return nodes
    .map(traverse)
    .filter((node) => node !== null);
}

export function mapTree(nodes, mapper) {
  return nodes.map((node) => ({
    ...mapper(node),
    children: node.children ? mapTree(node.children, mapper) : []
  }));
}

export function highlightMatches(nodes) {
  const cloned = structuredClone(nodes);
  cloned.forEach(function annotate(node) {
    if (node.isMatch) {
      node.highlight = true;
    }
    if (node.children) {
      node.children.forEach(annotate);
    }
  });
  return cloned;
}

export function flatten(nodes) {
  return nodes.flatMap((node) => [node, ...(node.children ? flatten(node.children) : [])]);
}
