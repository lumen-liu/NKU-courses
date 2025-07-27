#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n, m, a, b;
    int res = 0;
    cin >> n >> m >> a >> b;

    if (n < m || a < b / m) // 如果 n < m 或者 a < b/m ，那么选择第一种票价
    {
        res = n * a;
    }
    else // 否则选择第二种票价
    {
        res = (n / m) * b; // 购买完整的车次所需的费用
        if (n % m != 0) // 如果有剩余的车次需要购买
        {
            res += min((n % m) * a, b); // 选择花费更少的方式购买剩余车次
        }
    }

    cout << res << endl;

    return 0;
}