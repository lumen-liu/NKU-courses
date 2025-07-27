#include<iostream>
using namespace std;


const int MAXN = 100;

int n;
int a[MAXN + 1]; // 存储1到n的数，从a[1]开始存储

void dfs(int k) 
{
    if (k > n) 
    { // 如果已经到了第n+1个位置，输出当前排列
        for (int i = 1; i <= n; i++) 
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = k; i <= n; i++) // 枚举当前位置可以填哪些数
    { 
        swap(a[k], a[i]); // 将第i个数和第k个数交换，相当于固定了第k个位置为a[i]
        dfs(k + 1); // 继续递归填下一个位置
        swap(a[k], a[i]); // 恢复原来的状态，即回溯
    }
}

int main() 
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        a[i] = i;
    }
    dfs(1); // 从第1个位置开始填数
    return 0;
}

