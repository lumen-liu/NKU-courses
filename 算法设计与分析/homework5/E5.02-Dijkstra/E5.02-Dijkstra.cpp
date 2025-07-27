#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000; // 最大节点数
const int INF = 1061109567; // 表示无穷大的一个大值
struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};
typedef pair<int, int> P; // first: 最小距离，second: 顶点编号
vector<Edge> G[MAXN];
int d[MAXN]; // 存储源点到各个点的最短距离
void dijkstra(int s) { // s为源点
    priority_queue<P, vector<P>, greater<P>> q; // 小根堆，用于存储最小距离和顶点编号
    fill(d, d + MAXN, INF); // 初始化所有距离为无穷大
    d[s] = 0; // 源点到自身的距离为0
    q.push(P(0, s)); // 将源点加入队列
    while (!q.empty()) { // 当队列不为空时循环
        P p = q.top(); // 取出队首元素（最小距离）
        q.pop(); // 弹出队首元素
        int v = p.second; // 取出顶点编号
        if (d[v] < p.first) continue; // 如果当前顶点的最短距离已经更新过，则忽略该顶点
        for (int i = 0; i < G[v].size(); i++) { // 遍历与当前顶点相邻的所有边
            Edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) { // 如果可以通过当前顶点更新相邻顶点的最短距离，则更新并将其加入队列中
                d[e.to] = d[v] + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s; // 输入节点数、边数和源点编号
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z; // 输入边的起始节点、终止节点和边权值
        G[x].push_back(Edge(y, z)); // 将边存储在邻接表中
    }
    dijkstra(s); // 调用dijkstra算法计算最短路径
    for (int i = 1; i <= n; i++)
        cout << d[i] << " "; // 输出结果
    return 0;
}