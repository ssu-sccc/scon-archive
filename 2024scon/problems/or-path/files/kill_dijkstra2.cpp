#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
namespace graph{
    void shuffle_edge(std::vector<std::pair<int,int>> &vec){
        shuffle(vec.begin(), vec.end());
        for(auto &i : vec) if(rnd.next(0, 1)) std::swap(i.first, i.second);
    }
 
    void relabel_vertex(int n, std::vector<std::pair<int,int>> &edges){
        std::vector<int> id(n+1);
        std::iota(id.begin(), id.end(), 0);
        for(auto &i : edges) i.first = id[i.first], i.second = id[i.second];
    }
 
    std::vector<std::pair<int,int>> make_tree(int n){
        if(n == 1) return {};
        if(n == 2) return { std::make_pair(1, 2) };
 
        std::vector<int> a(n-2), deg(n+1);
        for(auto &i : a) i = rnd.next(1, n);
        for(auto i : a) deg[i]++;
 
        std::vector<std::pair<int,int>> res;
        std::priority_queue<int> pq;
        for(int i=n; i; i--) if(!deg[i]) pq.emplace(i);
        for(auto i : a){
            int j = pq.top(); pq.pop();
            res.emplace_back(std::min(i,j), std::max(i,j));
            if(!--deg[i]) pq.push(i);
        }
        int u = pq.top(); pq.pop();
        int v = pq.top(); pq.pop();
        res.emplace_back(u, v);
        shuffle_edge(res);
        return res;
    }
 
    std::vector<std::pair<int,int>> make_cycle(int n){
        std::vector<std::pair<int,int>> res;
        std::vector<int> ord(n); std::iota(ord.begin(), ord.end(), 1);
        shuffle(ord.begin(), ord.end());
        for(int i=0; i<n; i++) res.emplace_back(ord[i], ord[(i+1)%n]);
        return res;
    }
 
    std::vector<std::pair<int,int>> make_simple_connected(int n, int m){
        assert(m >= n - 1);
        assert(m <= 1LL * n * (n - 1) / 2);
        if(n <= 5000){
            auto tree = make_tree(n);
            for(auto &i : tree) if(i.first > i.second) std::swap(i.first, i.second);
            std::sort(tree.begin(), tree.end());
 
            std::vector<std::pair<int,int>> edges;
            for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(!std::binary_search(tree.begin(), tree.end(), std::make_pair(i, j))) edges.emplace_back(i, j);
            shuffle(edges.begin(), edges.end());
            edges.resize(m - tree.size());
            for(auto &i : tree) edges.push_back(i);
            return edges;
        }
        else{
            auto edges = make_tree(n);
            std::vector<std::set<int>> st(n+1);
            for(auto i : edges){
                st[i.first].insert(i.second);
                st[i.second].insert(i.first);
            }
            while(edges.size() < m){
                int u, v;
                do{
                    u = rnd.next(1, n-1);
                    v = rnd.next(u+1, n);
                }while(st[u].count(v));
                edges.emplace_back(u, v);
                st[u].insert(v);
                st[v].insert(u);
            }
            return edges;
        }
    }
}
 
int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
 
    int N = opt<int>("N");
    int M;
    if (__testlib_opts.count("M")) { M = opt<int>("M"); }
    else { M = rnd.next(N, int(min(300'000ll, 1ll*N*(N-1)/2))); }
 
    vector<pair<int, int>> edges = graph::make_simple_connected(N-1, M-2);
    graph::shuffle_edge(edges);
 
    cout << N << " " << M << "\n";
    for(auto [X, Y] : edges) {
        auto Z = rnd.next(0ll, (1ll << 59)-1);
        cout << X << " " << Y << " " << Z << "\n";
    }
    cout << 1 << " " << N-1 << " " << (1ll << 59) << "\n";
    cout << N-1 << " " << N << " " << (1ll << 59) << "\n";
    return 0;
}
