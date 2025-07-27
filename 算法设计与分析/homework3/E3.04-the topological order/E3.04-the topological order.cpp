#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n, 0); // 记录每个节点的入度
    vector<vector<int>> graph(n); // 邻接表
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // 添加边
        ++indegree[v]; // 更新入度
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) 
    {
        if (indegree[i] == 0) 
        { // 找到入度为0的节点
            q.push(i);
        }
    }

    vector<int> top_order;
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();
        top_order.push_back(cur); // 将当前节点加入结果数组中
        for (int neighbor : graph[cur]) 
        { // 更新邻接节点的入度
            --indegree[neighbor];
            if (indegree[neighbor] == 0) 
            { // 如果入度为0则加入队列
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << top_order[i] << " ";
    }
    cout << endl;

    return 0;
}
