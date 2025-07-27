#include <bits/stdc++.h>
using namespace std;
bool need_evicite(vector<int> vec, int a)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == a)
            return false;
    }
    return true;
}
bool ifFF(vector<int> vecc, vector<int> vecr, int pos, vector<int>& newvecc)
{
    int num = 0;
    for (int i = 0; i < vecc.size(); i++)
    {
        int m = 0;
        for (int j = pos + 1; j < vecr.size(); j++)
        {
            if (vecr[j] == vecc[i])
            {
                m++;
                num++;
                break;
            }
        }
        if (m == 0) // 若m==0，说明后半请求序列无当前缓冲区中的该元素，将其增加到新缓冲区中
            newvecc.push_back(vecc[i]);
    }
    return num != vecc.size();
}
int getpos1(vector<int> vec, int pos, int a)
{
    for (int i = pos + 1; i < vec.size(); i++)
    {
        if (vec[i] == a)
            return i; // 在后半部分找时，找到第一个就要返回
    }
    return -1; // 其实没啥实际用处，因为给定的输入肯定能让函数有返回。
}
int getpos2(vector<int> vec, int pos, int a)
{
    int m = 0;
    for (int i = 0; i < pos; i++)
    {
        if (vec[i] == a)
            m = i; // 在前半部分找时，需要找最后一次被使用过的下标，因此要不断更新m
    }
    return m;
}
int main()
{
    int k, n, s;
    cin >> k >> n >> s;
    vector<int> cache;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        cache.push_back(t);
    }
    vector<int> requests(s);
    for (int i = 0; i < s; i++)
        cin >> requests[i];
    for (int i = 0; i < requests.size(); i++)
    {
        if (cache.size() < k && need_evicite(cache, requests[i])) // 若缓冲区未满且无当前数据
        {
            cache.push_back(requests[i]); // 将当前数据加入缓冲区
        }
        else if (!need_evicite(cache, requests[i])) // 若缓冲区中已有当前数据，直接输出，无需操作
            continue;
        else if (need_evicite(cache, requests[i]) && cache.size() == k) // 若缓冲区无当前数据且缓冲区已满
        {
            vector<int> newcache;                    // 新缓冲区，后期回溯时用到
            if (!ifFF(cache, requests, i, newcache)) // 若缓冲区中所有数据都能在之后的请求序列中找到
            {
                int max = -1;
                int far = -1;               // 保存最远的数据的下标
                vector<int> d(k);           // 保存距离的数组
                for (int j = 0; j < k; j++) // 遍历当前缓冲区，为每个数据赋距离
                {
                    d[j] = getpos1(requests, i, cache[j]); // getpos1依次返回缓冲区中各个数据对应的下标
                    if (d[j] > max)                        // 直接利用该下标来反映后面数据距离的远近，越大说明离得越远
                    {
                        max = d[j];
                        far = j;
                    }
                }
                cout << cache[far] << ' '; // 扔掉最远的那个数据，然后替换成requests[i]
                cache[far] = requests[i];
            }
            else
            {
                int min = 10000;
                int far = -1;
                vector<int> d(newcache.size());
                for (int j = 0; j < newcache.size(); j++) // 遍历当前缓冲区，为每个数据赋距离
                {
                    d[j] = getpos2(requests, i, newcache[j]); // getpos2返回的是前半部分中，缓冲区数据对应的下标
                    if (d[j] < min)
                    {
                        min = d[j]; // 这时要扔掉最长访问过的，即下标最小的，因此不断更新min
                        far = j;
                    }
                }
                cout << newcache[far] << ' ';
                for (int j = 0; j < cache.size(); j++)
                {
                    if (cache[j] == newcache[far])
                    {
                        cache[j] = requests[i]; // 扔掉最久访问过的
                        break;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}