#include<bits/stdc++.h>
using namespace std;

// 暴力枚举法求最长公共子序列
void exchange(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
        {
            a[i] = 1;
            return;
        }
        else
        {
            a[i] = 0;
        }
    }
    return;
}
int lastpos(string a, char c)
{
    int k = -1;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == c)
        {
            k = i;
        }
    }
    return k;
}
int brute_force(const string& A, const string& B, vector<string>& LCS)
{
    int m = A.length();
    int n = B.length();
    int* x = new int[m] {0};
    int sum = 0;
    for (long long int i = 0; i < pow(2, m); i++)
    {
        int t = 0;
        exchange(x, m);
        int k = -2;
        for (int j = 0; j < m; j++)
        {
            if (x[j] != 0)
            {
                int pos = lastpos(B, A[j]);
                if (pos == -1)
                {
                    break;
                }
                if (pos >= k)
                {
                    t++;
                    k = pos;
                }
                else
                {
                    break;
                }
            }
        }
        sum = sum > t ? sum : t;
    }
    return sum;
}


// 动态规划法求最长公共子序列
int dynamic_programming(const string& A, const string& B, vector<string>& LCS)
{
    int m = A.length(), n = B.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
    //int len = dp[m][n];
    //int i = m, j = n;
    //while (i > 0 && j > 0)
    //{
    //    if (A[i - 1] == B[j - 1])
    //    {
    //        LCS.insert(LCS.begin(), string(1, A[i - 1]));
    //        i--;
    //        j--;
    //    }
    //    else if (dp[i - 1][j] >= dp[i][j - 1])
    //        i--;
    //    else
    //        j--;
    //}
}

int main()
{
    srand(time(NULL)); // 初始化随机数种子

    // 生成大小为5的随机序列
    cout << "生成大小为5的随机序列" << endl;
    int m = 5;
    string A, B;
    for (int i = 0; i < m; i++)
    {
        A += rand() % 26 + 'a';
        B += rand() % 26 + 'a';
    }


    // 输出随机序列
    cout << "Sequence A: " << A << endl;
    cout << "Sequence B: " << B << endl;

    // 计算最长公共子序列并输出
    vector<string> LCS1;
    clock_t start = clock();
    int res = brute_force(A, B, LCS1);
    clock_t end = clock();
    cout << "LCS (brute force): "<< res <<", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    LCS1.clear();
    start = clock();
    res = dynamic_programming(A, B, LCS1);
    end = clock();
    cout << "LCS (dynamic programming): " << res << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // 生成大小为25的随机序列
    cout << "生成大小为25的随机序列" << endl;
    m = 25;
    string C, D;
    for (int i = 0; i < m; i++)
    {
        C += rand() % 26 + 'a';
        D += rand() % 26 + 'a';
    }

    // 输出随机序列
    cout << "Sequence C: " << C << endl;
    cout << "Sequence D: " << D << endl;

    // 计算最长公共子序列并输出
    vector<string> LCS2;
    start = clock();
    res = brute_force(C, D, LCS2);
    end = clock();
    cout << "LCS (brute force): "<< res << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    LCS2.clear();
    start = clock();
    res = dynamic_programming(C, D, LCS2);
    end = clock();
    cout << "LCS (dynamic programming): "<< res << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    return 0;
}
