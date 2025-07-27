#include<bits/stdc++.h>
using namespace std;
// 定义工作的开始时间和结束时间的结构体
struct Job {
    int start_time;
    int end_time;
};

// 区间调度算法函数
vector<Job> interval_scheduling(int n, vector<Job>& jobs) 
{
    // 按结束时间从小到大排序
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) { return a.end_time < b.end_time; });
    // 初始化结果数组，加入第一个工作
    vector<Job> result{ jobs[0] };
    // 遍历其余工作
    for (int i = 1; i < n; i++) 
    {
        // 如果当前工作的开始时间晚于结果数组中最后一个工作的结束时间
        if (jobs[i].start_time >= result.back().end_time) 
        {
            // 将当前工作加入结果数组
            result.push_back(jobs[i]);
        }
    }
    return result;
}

int main() 
{
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> jobs[i].start_time >> jobs[i].end_time;
    }
    vector<Job> result = interval_scheduling(n, jobs);
    cout << result.size() << endl;
    system("pause");
    return 0;
}
