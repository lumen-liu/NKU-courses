#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000; // 定义图的最大节点数
vector<int> adj[N]; // 存储图的邻接表
bool vis[N]; // 标记节点是否被遍历过

void BFS(int s, vector<int>& comp) 
{
    queue<int> q; // 定义队列用于BFS
    q.push(s); // 将起始节点s放入队列
    vis[s] = true; // 标记起始节点已经被访问过
    while (!q.empty()) 
    { // 当队列不为空时
        int u = q.front(); // 取出队首节点u
        q.pop(); // 弹出队首节点
        comp.push_back(u); // 将节点u放入当前连通分量
        for (int v : adj[u]) 
        { // 遍历u的邻居节点v
            if (!vis[v]) 
            { // 如果节点v没有被访问过
                vis[v] = true; // 标记节点v已经被访问过
                q.push(v); // 将节点v放入队列
            }
        }
    }
}

void DFS(int u, vector<int>& comp) 
{
    vis[u] = true; // 标记节点u已经被访问过
    comp.push_back(u); // 将节点u放入当前连通分量
    for (int v : adj[u]) 
    { // 遍历节点u的邻居节点v
        if (!vis[v]) 
        { // 如果节点v没有被访问过
            DFS(v, comp); // 递归地访问节点v
        }
    }
}

int main() {
    int n, m, i;
    cin >> n >> m >> i; // 输入节点数、边数和需要查找连通分量的节点编号
    for (int j = 0; j < m; j++) {
        int u, v;
        cin >> u >> v; // 输入一条边的两个端点
        adj[u + 1].push_back(v + 1); // 存储边的信息
        adj[v + 1].push_back(u + 1);
    }
    vector<int> bfs_comp, dfs_comp; // 分别存储BFS和DFS找到的连通分量
    BFS(i + 1, bfs_comp); // 执行BFS算法
    memset(vis, 0, sizeof(vis)); // 初始化标记数组
    DFS(i + 1, dfs_comp); // 执行DFS算法
    for (int u : bfs_comp) {
        cout << (u - 1) << " "; // 输出BFS找到的连通分量
    }
    cout << endl;
    for (int u : dfs_comp) {
        cout << (u - 1) << " "; // 输出DFS找到的连通分量
    }
    cout << endl;
    return 0;
}
