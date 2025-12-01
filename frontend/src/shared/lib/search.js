function normalise(value) {
  return value.toLowerCase();
}

function nodeMatches(node, query) {
  if (!query) return true;
  const target = normalise(query);
  return normalise(node.displayName ?? node.name ?? '').includes(target);
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

    if (isMatch || mappedChildren.length > 0) {
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
