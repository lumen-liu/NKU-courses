#include<iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n; // 读入一个整数n
    if (n >= 0) // 如果n为非负数，直接输出n并退出
    {
        cout << n;
    }
    else // 如果n为负数，需要进行转换
    {
        n = abs(n); // 将n取绝对值，方便进行下一步计算
        if (n < 10) // 如果n的绝对值小于10，则输出0
        {
            cout << "0";
        }
        else // 如果n的绝对值大于等于10，则进行下一步计算
        {
            int last_two_digits = n / 100; // 取n的除去倒数第二位和倒数第一位的数
            int last_digit = n % 10; // 取n的个位数
            int second_last_digit = (n / 10) % 10; // 取n的十位数
            // 将n的倒数第二位和倒数第一位组成的两位数与n的个位数、十位数分别比较，取较大值并输出其相反数
            cout << -min(last_two_digits * 10 + last_digit, last_two_digits * 10 + second_last_digit);
        }
    }
}
