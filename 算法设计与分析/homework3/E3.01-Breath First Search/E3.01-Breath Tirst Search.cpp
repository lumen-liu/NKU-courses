#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000;
vector<int> G[N]; // 邻接表存储图
int layer[N]; // 用于存储每个节点所在的层数
bool vis[N]; // 标记节点是否已经被访问过
queue<int> Q; // 用于存储待遍历的节点

void BFS(int start)
{
    memset(vis, 0, sizeof(vis)); // 初始化所有节点未访问过
    layer[start] = 0; // 起始节点的层数为0
    vis[start] = true; // 标记起始节点已访问过
    Q.push(start); // 将起始节点放入队列

    while (!Q.empty())
    {
        int u = Q.front(); // 取出队首节点
        Q.pop(); // 弹出队首节点
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!vis[v])// 如果节点v未访问过
            {
                layer[v] = layer[u] + 1; // 更新节点v的层数
                vis[v] = true; // 标记节点v已访问过
                Q.push(v); // 将节点v放入队列
            }
        }
    }
}

int main()
{
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u + 1].push_back(v + 1); // 将边(u,v)加入邻接表
        G[v + 1].push_back(u + 1);;// 无向图需要将边(v,u)也加入邻接表
    }
    BFS(start + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << layer[i] << " ";
    }

    return 0;
}
