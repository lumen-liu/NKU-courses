#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int N = 1000; // 定义最大节点数
vector<int> graph[N]; // 邻接表存储图
int colors[N]; // 用来标记每个节点的颜色，初始化为0

bool BFS(int s) // BFS遍历
{ 
    queue<int> q;
    q.push(s);
    colors[s] = 1; // 将起始节点的颜色标记为1
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) 
        {
            if (colors[v] == colors[u]) return false; // 如果相邻节点颜色相同，则不是二分图
            if (colors[v] == 0) // 如果相邻节点未被标记颜色
            { 
                colors[v] = -colors[u]; // 将其颜色标记为与当前节点不同的颜色
                q.push(v);
            }
        }
    }
    return true;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
    {
        if (colors[i] == 0) // 如果当前节点未被标记颜色
        { 
            if (!BFS(i)) // 如果以当前节点为起始节点的子图不是二分图
            { 
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
