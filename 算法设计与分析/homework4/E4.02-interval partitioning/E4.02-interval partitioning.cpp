#include<bits/stdc++.h>
using namespace std;

int interval_partitioning(int n, vector<pair<int, int>> lectures) 
{
    // 按照讲座的结束时间升序排序
    sort(lectures.begin(), lectures.end(), [](auto& a, auto& b) {return a.second < b.second; });

    // 用一个vector存储已经分配讲座的教室的最后时间
    vector<int> classrooms;

    // 对于每个讲座，尝试将其分配到已有的教室中或新建一个教室
    for (int i = 0; i < n; i++) 
    {
        bool scheduled = false;
        for (int j = 0; j < classrooms.size(); j++) 
        {
            // 如果当前讲座可以被分配到该教室，则分配
            if (lectures[i].first >= classrooms[j]) 
            {
                classrooms[j] = lectures[i].second; // 更新该教室的最后时间
                scheduled = true;
                break;
            }
        }
        // 如果无法被分配到任何一个教室，则新建一个教室
        if (!scheduled) 
        {
            classrooms.push_back(lectures[i].second);
        }
    }

    // 返回使用的教室数
    return classrooms.size();
}

int main() {
    int n;
    cin >> n;

    // 读入每个讲座的开始和结束时间，并构造一个vector<pair<int, int>>存储它们
    vector<pair<int, int>> lectures;
    for (int i = 0; i < n; i++) 
    {
        int start, end;
        cin >> start >> end;
        lectures.push_back({ start, end });
    }

    // 调用interval_partitioning函数并输出结果
    cout << interval_partitioning(n, lectures) << endl;
    system("pause");

    return 0;
}
