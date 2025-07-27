#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1000;
struct Edge {
    int u, v, cost;
    Edge(int u, int v, int cost) : u(u), v(v), cost(cost) {}
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};
int p[MAXN];
int find(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find(p[x]);
}
void unite(int x, int y) {
    p[find(x)] = find(y);
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end()); // 将所有边按边权从小到大排序
    for (int i = 1; i <= n; i++)
        p[i] = i; // 初始化并查集
    int res = 0;
    for (Edge e : edges) { // 遍历所有边
        if (!same(e.u, e.v)) { // 如果两个顶点不在同一个连通分量中，则将它们合并，并将边权累加到结果中
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res; // 返回最小生成树的边权之和
}
int main() {
    int n, m;
    cin >> n >> m; // 输入节点数和边数
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // 输入每条边的起始节点、终止节点和边权值
        edges.emplace_back(u, v, w); // 将边存储在数组中
    }
    cout << kruskal(edges, n); // 调用kruskal算法计算最小生成树的边权之和并输出结果
    return 0;
}