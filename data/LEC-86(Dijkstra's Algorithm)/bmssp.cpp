// bmssp.cpp
// BMSSP (Bounded Multi-Source Shortest Path Algorithm) implementation for single-source SSSP.
// Practical BMSSP-style SSSP implementation (approximate DS).
// Implements the structure of Algorithm 1,2,3 from Duan et al. (arXiv:2504.17033) [https://arxiv.org/pdf/2504.17033]
// but uses a simplified heap-based data-structure for D (so correct, not paper-fast).

#include <bits/stdc++.h>
using namespace std;

const double INF = numeric_limits<double>::infinity();
const double EPS = 1e-12;

struct Edge {
    int to;
    double w;
    Edge(int t=0, double ww=0): to(t), w(ww) {}
};

struct DiGraph {
    int n;
    vector<vector<Edge>> adj;
    DiGraph(int n_ = 0): n(n_), adj(n_) {}
    void add_edge(int u, int v, double w) {
        adj[u].emplace_back(v, w);
    }
};

// ------------------------
// SimpleD : simplified approximation of the paper's Lemma 3.3 DS
// - Uses min-heap of (value, vertex) and present map to detect stale entries.
// - insert(pair(v, val)), batch_prepend(vector<pair>), pull() -> (Bi, Si)
// ------------------------
struct SimpleD {
    // min-heap: smallest val on top
    struct Node {
        double val;
        int v;
        Node(double a=0, int b=0): val(a), v(b) {}
        bool operator>(Node const& other) const {
            if (fabs(val - other.val) > 1e-18) return val > other.val;
            return v > other.v;
        }
    };
    priority_queue<Node, vector<Node>, greater<Node>> heap;
    unordered_map<int,double> present; // best value currently known for vertex

    void initialize(long long M, double B) {
        // M and B are unused for simplified DS but kept for API parity
        while(!heap.empty()) heap.pop();
        present.clear();
    }
    void insert(pair<int,double> p) {
        int v = p.first; double val = p.second;
        auto it = present.find(v);
        if (it == present.end() || val < it->second) {
            present[v] = val;
            heap.emplace(val, v);
        }
    }
    void batch_prepend(const vector<pair<int,double>>& items) {
        for (auto &it : items) insert(it);
    }
    // Pull returns pair<bool, pair<double, vector<int>>>.
    // bool=false indicates empty.
    pair<bool, pair<double, vector<int>>> pull() {
        while (!heap.empty()) {
            Node nd = heap.top(); heap.pop();
            auto it = present.find(nd.v);
            if (it != present.end() && fabs(it->second - nd.val) <= 0.0) {
                // found fresh
                present.erase(it);
                return {true, {nd.val, vector<int>{nd.v}}};
            }
            // stale entry -> skip
        }
        return {false, {{0.0}, {}}};
    }
    bool empty() const {
        return heap.empty();
    }
};

// ------------------------
// BMSSPRunner class: holds graph, db, pred, parameters, and algorithmic routines
// ------------------------
struct BMSSPRunner {
    DiGraph &G;
    int n;
    int source;
    vector<double> db;
    vector<int> pred;
    int k, t;
    int max_l;

    BMSSPRunner(DiGraph &G_, int s_): G(G_), n(G_.n), source(s_), db(n, INF), pred(n, -1) {
        db[source] = 0.0;
        if (n <= 2) {
            k = 2; t = 1;
        } else {
            double lg = max(1.0, log(max(2.0, (double)n)));
            k = max(2, (int)floor(pow(lg, 1.0/3.0)));
            t = max(1, (int)floor(pow(lg, 2.0/3.0)));
        }
        k = max(2, k);
        t = max(1, t);
        // choose a recursion depth l ~ ceil(log n / t)
        max_l = max(0, (int)ceil(log((double)(n+1)) / (double)max(1,t)));
    }

    // BaseCase: Dijkstra-like extracting up to k+1 vertices starting from S inside bound B
    pair<double, unordered_set<int>> BaseCase(double B, const unordered_set<int> &S) {
        vector<char> inH(n, 0);
        // min-heap: (db, v)
        struct PNode { double d; int v; };
        struct Cmp { bool operator()(PNode const& a, PNode const& b) const { 
            if (fabs(a.d - b.d) > 1e-18) return a.d > b.d; return a.v > b.v;
        }};
        priority_queue<PNode, vector<PNode>, Cmp> H;
        for (int x : S) {
            if (db[x] < B) {
                H.push({db[x], x});
                inH[x] = 1;
            }
        }
        vector<int> U0;
        while (!H.empty() && (int)U0.size() < (k + 1)) {
            PNode top = H.top(); H.pop();
            int u = top.v; double val = top.d;
            inH[u] = 0;
            if (fabs(val - db[u]) > 1e-15) continue; // stale
            U0.push_back(u);
            for (auto &e : G.adj[u]) {
                int v = e.to; double w = e.w;
                double newd = db[u] + w;
                if (newd <= db[v] && newd < B + EPS) {
                    if (newd + EPS < db[v]) {
                        db[v] = newd;
                        pred[v] = u;
                    }
                    if (!inH[v]) {
                        H.push({db[v], v});
                        inH[v] = 1;
                    }
                }
            }
        }
        if ((int)U0.size() <= k) {
            unordered_set<int> Uset(U0.begin(), U0.end());
            return {B, Uset};
        } else {
            double Bprime = -INF;
            for (int u : U0) Bprime = max(Bprime, db[u]);
            unordered_set<int> Uset;
            for (int u : U0) if (db[u] + EPS < Bprime) Uset.insert(u);
            return {Bprime, Uset};
        }
    }

    // FindPivots: performs up to k rounds of relaxations from S (bounded by B) and builds P and W
    pair<unordered_set<int>, unordered_set<int>> FindPivots(double B, const unordered_set<int> &S) {
        unordered_set<int> W = S;
        unordered_set<int> Wi_prev = S;
        for (int i = 1; i <= k; ++i) {
            unordered_set<int> Wi;
            for (int u : Wi_prev) {
                for (auto &e : G.adj[u]) {
                    int v = e.to; double w = e.w;
                    double newd = db[u] + w;
                    if (newd <= db[v] + EPS) {
                        if (newd + EPS < db[v]) { db[v] = newd; pred[v] = u; }
                        if (newd + EPS < B) Wi.insert(v);
                    }
                }
            }
            for (int x : Wi) W.insert(x);
            Wi_prev.swap(Wi);
            if ((long long)W.size() > (long long)k * (long long)S.size()) {
                // early stop
                unordered_set<int> P = S;
                return {P, W};
            }
        }
        // Build forest F among W using edges u->v where db[v] == db[u] + w (within EPS)
        unordered_map<int, vector<int>> children;
        unordered_map<int, int> parent;
        for (int u : W) {
            for (auto &e : G.adj[u]) {
                int v = e.to; double w = e.w;
                if (W.find(v) != W.end()) {
                    if (fabs(db[v] - (db[u] + w)) <= 1e-9) {
                        children[u].push_back(v);
                        parent[v] = u; // if multiple parents occur, we keep one; uniqueness assumed in theory
                    }
                }
            }
        }
        vector<int> roots;
        for (int u : W) if (parent.find(u) == parent.end()) roots.push_back(u);
        unordered_map<int,int> subtree_size;
        function<int(int)> dfs = [&](int u)->int {
            int s = 1;
            auto it = children.find(u);
            if (it != children.end()) {
                for (int v : it->second) s += dfs(v);
            }
            subtree_size[u] = s;
            return s;
        };
        for (int r : roots) dfs(r);
        unordered_set<int> P;
        for (int u : S) {
            auto it = subtree_size.find(u);
            if (it != subtree_size.end() && it->second >= k) P.insert(u);
        }
        return {P, W};
    }

    // BMSSP recursion
    pair<double, unordered_set<int>> BMSSP(int l, double B, const unordered_set<int> &S) {
        if (l <= 0) return BaseCase(B, S);

        auto [P, W] = FindPivots(B, S);
        SimpleD D;
        long long M = 1LL << max(0, (l - 1) * t); // may overflow for large l,t but it's unused
        D.initialize(M, B);
        for (int x : P) D.insert({x, db[x]});
        double B0 = INF;
        if (!P.empty()) {
            for (int x : P) B0 = min(B0, db[x]);
        } else {
            B0 = B;
        }
        unordered_set<int> U;
        // limit_U approx: min(k^(2*l*t), 4*n) to keep sizes manageable
        double powlimit = 1.0;
        if (k > 1 && t > 0) {
            // may overflow; do it conservatively
            double exponent = 2.0 * l * (double)t;
            double candidate = pow((double)k, exponent);
            powlimit = min(candidate, (double)4 * n);
        } else powlimit = (double)4 * n;
        long long limit_U = (long long)max( (double)4, floor(powlimit) );

        while ((long long)U.size() < limit_U && !D.empty()) {
            auto pulled = D.pull();
            if (!pulled.first) break;
            double Bi = pulled.second.first;
            vector<int> Si_vec = pulled.second.second;
            unordered_set<int> Si(Si_vec.begin(), Si_vec.end());
            auto [Bprime_i, Ui] = BMSSP(l-1, Bi, Si);
            // U = U union Ui
            for (int x : Ui) U.insert(x);
            // relax edges from Ui
            vector<pair<int,double>> K;
            for (int u : Ui) {
                for (auto &e : G.adj[u]) {
                    int v = e.to; double w = e.w;
                    double newd = db[u] + w;
                    if (newd <= db[v] + EPS) {
                        if (newd + EPS < db[v]) { db[v] = newd; pred[v] = u; }
                        if (newd + EPS >= Bi && newd + EPS < B) {
                            D.insert({v, newd});
                        } else if (newd + EPS >= Bprime_i && newd + EPS < Bi) {
                            K.emplace_back(v, newd);
                        }
                    }
                }
            }
            // also add x in Si with db[x] in [Bprime_i, Bi)
            for (int x : Si) {
                if (db[x] + EPS >= Bprime_i && db[x] + EPS < Bi) K.emplace_back(x, db[x]);
            }
            D.batch_prepend(K);
            B0 = min(B0, Bprime_i);
        }
        double Bprime = min(B0, B);
        unordered_set<int> U_final = U;
        for (int x : W) if (db[x] + EPS < Bprime) U_final.insert(x);
        return {Bprime, U_final};
    }

    // run top-level SSSP driver
    vector<double> run() {
        int l = max_l;
        double B = INF;
        unordered_set<int> S{source};
        BMSSP(l, B, S);
        return db;
    }
};

// convenience wrapper
vector<double> sssp_bmssp(DiGraph &G, int source) {
    BMSSPRunner runner(G, source);
    return runner.run();
}

// ------------------------
// Example main
// ------------------------
int main() {
    DiGraph G(6);
    G.add_edge(0,1,7);
    G.add_edge(0,2,9);
    G.add_edge(0,5,14);
    G.add_edge(1,2,10);
    G.add_edge(1,3,15);
    G.add_edge(2,3,11);
    G.add_edge(2,5,2);
    G.add_edge(3,4,6);
    G.add_edge(4,5,9);

    vector<double> dist = sssp_bmssp(G, 0);
    cout << "distances:";
    for (double d : dist) {
        if (!isfinite(d)) cout << " INF";
        else cout << " " << (long long) d; // distances are integral here; change as needed
    }
    cout << "\n";
    return 0;
}
