#include <bits/stdc++.h>
using namespace std;

struct State 
{
    vector<int> assignment;
    int cost;

    // 运算符重载 定义优先队列中状态的优先级
    bool operator<(const State& other) const 
    {
        return cost > other.cost; 
    }
};

// 获取备课总时间
int get_cost(vector<int>& assignment, vector<vector<int>>& times) 
{
    int total_time = 0;
    for (int i = 0; i < assignment.size(); i++) 
    {
        total_time += times[i][assignment[i]];
    }
    return total_time;
}

void assign_courses(vector<vector<int>>& times) 
{
    int n = times.size();
    priority_queue<State> heap;
    heap.push({ {}, 0 }); // 初始状态，没有人分配课程，备课总时间为0
    while (!heap.empty()) 
    {
        State state = heap.top();
        heap.pop();
        // 找到了一个满足条件的分配方案
        if (state.assignment.size() == n) 
        { 
            // 输出分配方案
            cout << "Assignment: ";
            for (int i = 0; i < state.assignment.size(); i++) 
            {
                cout << char(state.assignment[i] + 'A') << " ";
            }
            cout << endl;
            // 输出备课总时间
            cout << "Total cost: " << state.cost << endl;
            break;
        }
        for (int i = 0; i < n; i++) 
        {
            bool is_assigned = false;
            for (int j : state.assignment) 
            {
                if (j == i) 
                {
                    is_assigned = true; // 这个人已经分配了课程
                    break;
                }
            }
            if (is_assigned) continue;
            State new_state = state;
            new_state.assignment.push_back(i); // 分配课程
            new_state.cost = get_cost(new_state.assignment, times); // 计算备课总时间
            heap.push(new_state); // 将新状态加入优先队列
        }
    }
}

int main() {
    vector<vector<int>> times = { {2, 10, 9, 7},
                                  {15, 4, 14, 8},
                                  {13, 14, 16, 11},
                                  {4, 15, 13, 9} 
                                };
    assign_courses(times);
    system("pause");
    return 0;
}
