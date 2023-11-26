#include <iostream>
#include <queue>
#include <numeric>
#include "pystrlib.hpp"

struct edge { int to, nxt; } g[20005];
int head[2000], cnt;

inline void add_edge(int f, int t) { g[++cnt] = (edge) { t, head[f] }; head[f] = cnt; }

std::queue<int> Q;
int V[2000], n;

int main() {
    freopen("day12.txt", "r", stdin);
    {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::vector<std::string> to = lib::split(std::get<2>(lib::partition(line, " <-> ")), ", ");
            for (const std::string &str : to) add_edge(n, std::stoi(str));
            ++n;
        }
    }
    Q.push(0); V[0] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = head[u]; i; i = g[i].nxt)
            if (!V[g[i].to]) V[g[i].to] = 1, Q.push(g[i].to);
    }
    std::cout << std::accumulate(V, V + n, 0) << std::endl;
    return 0;
}