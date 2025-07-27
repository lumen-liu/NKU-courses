#include <bits/stdc++.h>
#include <ctime>

using namespace std;

int knapsack(int V, int n, vector<pair<int, int>>& items) {
    // 初始化f数组
    vector<vector<int>> f(n + 1, vector<int>(V + 1, 0));

    // 动态规划求解
    for (int i = 1; i <= n; i++) {
        int vi = items[i - 1].first, wi = items[i - 1].second;
        for (int j = 1; j <= V; j++) {
            if (j < vi) {
                f[i][j] = f[i - 1][j];
            }
            else {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - vi] + wi);
            }
        }
    }

    return f[n][V];
}

int knapsack_enum(int V, int n, vector<pair<int, int>>& items) {
    int ans = 0;
    // 枚举所有情况
    for (int i = 0; i < (1 << n); i++) {
        int v = 0, w = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                v += items[j].first;
                w += items[j].second;
            }
        }
        if (v <= V) {
            ans = max(ans, w);
        }
    }
    return ans;
}

int main() {
    
    cout << "以下为给定测试样例所得结果" << endl;
    int V = 5, n = 4;
    vector<pair<int, int>> items{ {2, 12}, {1, 10}, {3, 20}, {2, 15} };

    // 测试DP方法
    clock_t start = clock();
    int ans_dp = knapsack(V, n, items);
    clock_t end = clock();
    cout << "DP method: " << ans_dp << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // 测试枚举法
    start = clock();
    int ans_enum = knapsack_enum(V, n, items);
    end = clock();
    cout << "Enum method: " << ans_enum << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    cout << "以下为随机数生成测试样例所得结果" << endl;
    cout << "物品数量为4" << endl;
    // 物品数量为4
    int V1 = 50, n1 = 4;
    vector<pair<int, int>> items1(n1);
    srand((unsigned int)time(NULL));  // 随机数种子
    for (int i = 0; i < n1; i++) {
        int vi = rand() % 20 + 1, wi = rand() % 30 + 1;
        items1[i] = { vi, wi };
    }

    // 测试DP方法
    start = clock();
    int ans_dp1 = knapsack(V1, n1, items1);
    end = clock();
    cout << "DP method with n=4: " << ans_dp1 << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // 测试枚举法
    start = clock();
    int ans_enum1 = knapsack_enum(V1, n1, items1);
    end = clock();
    cout << "Enum method with n=4: " << ans_enum1 << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    cout << endl;
    cout << "物品数量为25" << endl;
    // 物品数量为25
    int V2 = 100, n2 = 25;
    vector<pair<int, int>> items2(n2);
    for (int i = 0; i < n2; i++) {
        int vi = rand() % 20 + 1, wi = rand() % 30 + 1;
        items2[i] = { vi, wi };
    }

    // 测试DP
    start = clock();
    int ans_dp2 = knapsack(V2, n2, items2);
    end = clock();
    cout << "DP method with n=25: " << ans_dp2 << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    // 测试枚举法
    start = clock();
    int ans_enum2 = knapsack_enum(V2, n2, items2);
    end = clock();
    cout << "Enum method with n=25: " << ans_enum2 << ", time: " << setprecision(10) << double(end - start) / CLOCKS_PER_SEC << "s" << endl;

    system("pause");
    return 0;
}

