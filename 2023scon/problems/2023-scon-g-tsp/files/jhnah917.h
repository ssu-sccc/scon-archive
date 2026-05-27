#include "testlib.h"
#include <bits/stdc++.h>

namespace graph_gen{
    void shuffle_edge(std::vector<std::pair<int,int>> &edges, bool is_directed){
        shuffle(edges.begin(), edges.end());
        if(!is_directed) for(auto &i : edges) if(rnd.next(0, 1)) std::swap(i.first, i.second);
    }

    template<typename cost_t>
    void shuffle_edge(std::vector<std::tuple<int,int,cost_t>> &edges, bool is_directed){
        shuffle(edges.begin(), edges.end());
        if(!is_directed) for(auto &[u,v,w] : edges) if(rnd.next(0, 1)) std::swap(u, v);
    }

    void relabel_vertex(int n, std::vector<std::pair<int,int>> &edges){
        std::vector<int> id(n+1);
        std::iota(id.begin(), id.end(), 0);
        shuffle(id.begin()+1, id.end());
        for(auto &i : edges) i.first = id[i.first], i.second = id[i.second];
    }

    template<typename cost_t>
    void relabel_vertex(int n, std::vector<std::tuple<int,int,cost_t>> &edges){
        std::vector<int> id(n+1);
        std::iota(id.begin(), id.end(), 0);
        shuffle(id.begin()+1, id.end());
        for(auto &[u,v,w] : edges) u = id[u], v = id[v];
    }

    std::vector<std::pair<int,int>> prufer_to_tree(int n, std::vector<int> a){
        if(n == 1) return {};
        if(n == 2) return { std::make_pair(1, 2) };
        assert(a.size() + 2 == n);
        assert(*std::min_element(a.begin(), a.end()) >= 1);
        assert(*std::max_element(a.begin(), a.end()) <= n);

        std::vector<int> deg(n+1);
        for(auto i : a) deg[i]++;

        std::vector<std::pair<int,int>> res;
        std::priority_queue<int> pq;
        for(int i=n; i; i--) if(!deg[i]) pq.emplace(i);
        for(auto i : a){
            int j = pq.top(); pq.pop();
            res.emplace_back(i, j);
            if(!--deg[i]) pq.push(i);
        }
        int u = pq.top(); pq.pop();
        int v = pq.top(); pq.pop();
        res.emplace_back(u, v);
        return res;
    }

    std::vector<std::pair<int,int>> make_tree(int n){
        if(n == 1) return {};
        if(n == 2) return { std::make_pair(1, 2) };

        std::vector<int> a(n-2);
        for(auto &i : a) i = rnd.next(1, n);
        return prufer_to_tree(n, a);
    }

    std::vector<std::pair<int,int>> make_cycle(int n){
        if(n == 1) return {};
        if(n == 2) return { std::make_pair(1, 2) };
        std::vector<std::pair<int,int>> res;
        std::vector<int> ord(n); std::iota(ord.begin(), ord.end(), 1);
        shuffle(ord.begin(), ord.end());
        for(int i=0; i<n; i++) res.emplace_back(ord[i], ord[(i+1)%n]);
        return res;
    }

    std::vector<std::pair<int,int>> make_undirected_simple_graph(int n, int m, std::vector<std::pair<int,int>> used={}){
        for(auto &[a,b] : used) if(a > b) std::swap(a, b);
        std::sort(used.begin(), used.end());
        std::vector<std::pair<int,int>> res;
        if(n <= 5000){
            for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(!std::binary_search(used.begin(), used.end(), std::make_pair(i, j))) res.emplace_back(i, j);
            shuffle(res.begin(), res.end());
            res.resize(m);
        }
        else{
            std::vector<std::set<int>> st(n+1);
            for(auto [u,v] : used) st[u].insert(v), st[v].insert(u);
            while(res.size() < m){
                int u, v;
                do u = rnd.next(1, n-1), v = rnd.next(u+1, n); while(st[u].count(v));
                res.emplace_back(u, v); st[u].insert(v); st[v].insert(u);
            }
        }
        return res;
    }

    std::vector<std::pair<int,int>> make_undirected_simple_connected_graph(int n, int m){
        assert(m >= n - 1);
        assert(m <= 1LL * n * (n - 1) / 2);
        auto tree = make_tree(n);
        auto edges = make_undirected_simple_graph(n, m-tree.size(), tree);
        edges.insert(edges.end(), tree.begin(), tree.end());
        return edges;
    }

    std::vector<std::pair<int,int>> make_undirected_connected_graph(int n, int m){
        assert(m >= n - 1);
        auto edges = make_tree(n);
        while(edges.size() < m){
            int u = -1, v = -1;
            while(u == v){
                u = rnd.next(1, n);
                v = rnd.next(1, n);
            }
            edges.emplace_back(u, v);
        }
        return edges;
    }
}

namespace graph_val{
    struct union_find{
        std::vector<int> p;
        union_find(int n) : p(n+1) { std::iota(p.begin(), p.end(), 0); }
        int find(int v){ return v == p[v] ? v : p[v] = find(p[v]); }
        bool merge(int u, int v){ return find(u) != find(v) && (p[p[u]]=p[v], true); }
        bool is_connected(int u, int v){ return find(u) == find(v); }
    };

    bool is_undirected_connected_graph(int n, const std::vector<std::pair<int,int>> &edges){
        union_find uf(n);
        for(const auto &[u,v] : edges) uf.merge(u, v);
        for(int i=2; i<=n; i++) if(!uf.is_connected(1, i)) return false;
        return true;
    }

    bool is_undirected_simple_connected_graph(int n, std::vector<std::pair<int,int>> edges){
        if(!is_undirected_connected_graph(n, edges)) return false;
        for(const auto &[u,v] : edges) if(u == v) return false;
        for(auto &[u,v] : edges) if(u > v) std::swap(u, v);
        sort(edges.begin(), edges.end());
        for(int i=1; i<edges.size(); i++) if(edges[i-1] != edges[i]) return false;
        return true;
    }

    bool is_forest(int n, const std::vector<std::pair<int,int>> &edges){
        union_find uf(n);
        for(const auto &[u,v] : edges) if(!uf.merge(u, v)) return false;
        return true;
    }

    bool is_tree(int n, const std::vector<std::pair<int,int>> &edges){
        return is_undirected_simple_connected_graph(n, edges) && is_forest(n, edges);
    }

    bool is_directed_acyclic_graph(int n, std::vector<std::pair<int,int>> &edges){
        std::vector<int> in(n+1);
        std::vector<std::vector<int>> gph(n+1);
        for(const auto &[u,v] : edges) gph[u].push_back(v), in[v]++;

        std::queue<int> que;
        for(int i=1; i<=n; i++) if(!in[i]) que.push(i);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto i : gph[v]) if(!--in[i]) que.push(i);
        }
        return std::count(in.begin(), in.end(), 0) == in.size();
    }
}