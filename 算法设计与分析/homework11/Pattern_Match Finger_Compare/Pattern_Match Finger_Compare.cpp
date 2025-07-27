#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BASE = 26;  // 字符集的基数
const int MOD = 1000000007;  // 取模的值

// 计算字符串的指纹值
int calculateFingerprint(const string& str, int length) {
    int fingerprint = 0;
    for (int i = 0; i < length; i++) {
        fingerprint = (fingerprint * BASE + (str[i] - 'a')) % MOD;
    }
    return fingerprint;
}

// 计算指纹的更新值
int calculateUpdatedFingerprint(int fingerprint, int length, char removedChar, char addedChar) {
    fingerprint = (fingerprint * BASE) % MOD;
    fingerprint = (fingerprint + (addedChar - 'a')) % MOD;

    int removedValue = (removedChar - 'a') * static_cast<int>(pow(BASE, length - 1)) % MOD;
    fingerprint = (fingerprint + MOD - removedValue) % MOD;

    return fingerprint;
}

int patternMatching(const string& X, const string& Y) {
    int n = X.length();
    int m = Y.length();

    if (n < m) {
        return -1;  // X的长度小于Y，Y无法匹配
    }

    // 计算模式串Y的指纹值
    int targetFingerprint = calculateFingerprint(Y, m);

    // 计算文本串X中第一个长度为m的子串的指纹值
    int currentFingerprint = calculateFingerprint(X, m);

    // 预先计算 BASE 的 m 次方，用于更新指纹时的计算
    int basePower = 1;
    for (int i = 0; i < m - 1; i++) {
        basePower = (basePower * BASE) % MOD;
    }

    // 逐个比较文本串X中的子串和模式串Y的指纹值
    for (int i = 0; i <= n - m; i++) {
        if (currentFingerprint == targetFingerprint) {
            // 如果指纹值匹配，进一步比较子串和模式串的内容
            if (X.substr(i, m) == Y) {
                return i;  // 匹配成功，返回第一个位置的索引
            }
        }

        // 更新指纹值
        if (i < n - m) {
            currentFingerprint = calculateUpdatedFingerprint(currentFingerprint, m, X[i], X[i + m]);
        }
    }

    return -1;  // 没有找到匹配的位置
}

int main() {
    string X, Y;
    cout << "请输入字符串X：";
    cin >> X;
    cout << "请输入字符串Y：";
    cin >> Y;

    int result = patternMatching(X, Y);
    cout << "Y在X中第一次出现的位置：" << result << endl;

    return 0;
}
