#include <iostream>
#include <cmath> // 引入数学库
#include <vector> // 引入容器库
#include <algorithm> // 引入算法库
using namespace std;

// 定义结构体，表示二维点
struct Point 
{
	double x;
	double y;
	Point(double x, double y) : x(x), y(y) {}
};

// 定义一个函数，用于计算两个点之间的欧几里得距离
double euclideanDistance(const Point& p1, const Point& p2) 
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy); // 调用sqrt函数计算平方根
}

// 定义一个函数，用于计算一组点中最近的两个点之间的欧几里得距离
double closestPair(vector<Point>& points) 
{
	sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) { return p1.x < p2.x; }); // 根据x坐标从小到大排序
	double minDist = euclideanDistance(points[0], points[1]); // 初始距离为前两个点的距离
	int left = 0;
	for (int i = 0; i < points.size(); i++) 
	{
		while (points[i].x - points[left].x > minDist) 
		{
			left++; // 左指针往右移，直到满足x坐标之差小于等于minDist
		}
		for (int j = left; j < i; j++) 
		{ // 只需遍历左指针和i之间的点
			double dist = euclideanDistance(points[i], points[j]); // 计算两个点之间的距离
			if (dist < minDist)
			{
				minDist = dist; // 如果距离小于当前最小距离，则更新最小距离
			}
		}
	}
	return minDist; // 返回最小距离
}

int main() 
{
	vector<Point> points{ {1, 2}, {3, 4}, {2, 7}, {8, 9}, {5, 6} }; // 初始化一组点
	double minDist = closestPair(points); // 计算最小距离
	cout << "最近的两个点之间的距离是：" << minDist << endl;
	return 0;
}