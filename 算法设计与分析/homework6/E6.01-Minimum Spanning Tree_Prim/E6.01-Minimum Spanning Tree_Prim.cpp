#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // 定义pair类型

const int MAXN = 100005;
const int INF = 11111111;

vector<pii> g[MAXN]; // 图的邻接表表示
bool vis[MAXN]; // 标记节点是否在最小生成树中

int prim(int n) {
    int ans = 0; // 最小生成树的边权和
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 最小堆
    pq.push(make_pair(0, 1)); // 从节点1开始

    while (!pq.empty()) {
        int u = pq.top().second; // 取出堆顶节点
        int w = pq.top().first; // 取出堆顶节点的权值
        pq.pop();

        if (vis[u]) continue; // 如果节点已经在最小生成树中，则跳过
        vis[u] = true; // 标记节点已经在最小生成树中

        ans += w; // 更新最小生成树的边权和

        for (auto& e : g[u]) { // 遍历节点u的邻接表
            int v = e.first;
            int weight = e.second;
            if (!vis[v]) {
                pq.push(make_pair(weight, v)); // 将节点v加入最小堆
            }
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    cout << prim(n) << endl;

    return 0;
}
