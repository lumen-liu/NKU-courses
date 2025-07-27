#include <bits/stdc++.h>
using namespace std;

// 二维点结构体
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    bool operator<(const Point& p) const {
        return x < p.x;
    }
};

// 计算两点之间的距离
double dist(const Point& a, const Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// 归并排序，并计算左右两边最小的距离
double merge(vector<Point>& P, int left, int mid, int right, double d) {
    vector<Point> mergeP;
    for (int i = left; i <= right; ++i) {
        mergeP.push_back(P[i]);
    }
    sort(mergeP.begin(), mergeP.end(), [](const Point& a, const Point& b) { return a.y < b.y; });

    for (int i = 0; i < mergeP.size(); ++i) {
        for (int j = i + 1; j < mergeP.size() && mergeP[j].y - mergeP[i].y < d; ++j) {
            double tmp = dist(mergeP[i], mergeP[j]);
            if (tmp < d) {
                d = tmp;
            }
        }
    }
    return d;
}

// 查找跨越左右两个区间的最小距离
double search(vector<Point>& P, int left, int right) {
    if (left >= right) {
        return INT_MAX;
    }
    int mid = (left + right) / 2;
    double d1 = search(P, left, mid);
    double d2 = search(P, mid + 1, right);
    double d = min(d1, d2);

    return merge(P, left, mid, right, d);
}

int main() {
    int n;
    cin >> n;
    vector<Point> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i].x >> P[i].y;
    }
    sort(P.begin(), P.end());

    double ans = search(P, 0, n - 1);
    cout << ans * ans << endl;

    return 0;
}
