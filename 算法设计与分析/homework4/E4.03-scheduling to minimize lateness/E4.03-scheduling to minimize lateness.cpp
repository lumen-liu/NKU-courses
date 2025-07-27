#include<bits/stdc++.h>
using namespace std;

// 定义工作结构体
struct Job {
    int id;                 // 工作 ID
    int processing_time;    // 处理时间
    int deadline;           // 截止时间
};

// 自定义排序函数，按照截止时间从小到大排序
bool cmp(Job a, Job b) 
{
    return a.deadline < b.deadline;
}

int main() 
{
    int n;
    cin >> n;

    // 创建工作列表
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) 
    {
        jobs[i].id = i + 1;   // 工作 ID 从 1 开始
        cin >> jobs[i].processing_time >> jobs[i].deadline;  // 输入处理时间和截止时间
    }

    // 对工作列表按照截止时间从小到大排序
    sort(jobs.begin(), jobs.end(), cmp);

    int current_time = 0;   // 当前时间初始化为 0
    int max_lateness = 0;   // 最大延迟时间初始化为 0
    vector<int> schedule;   // 调度表初始化为空

    // 对每个工作进行处理
    for (int i = 0; i < n; i++) 
    {
        current_time += jobs[i].processing_time;   // 更新当前时间
        int lateness = current_time - jobs[i].deadline;   // 计算延迟时间

        if (lateness > max_lateness) 
        {   // 更新最大延迟时间
            max_lateness = lateness;
        }

        schedule.push_back(jobs[i].id);   // 将工作 ID 添加到调度表中
    }

    // 最大延迟时间
    cout << max_lateness << endl;
    system("pause");
    return 0;
}
