#include<iostream>
#include<time.h> 
#include"Binary Search.h" // 导入二分查找函数头文件
using namespace std;

// O(n^2) 算法求解两数之和等于目标值的情况
void target_sum_nn(int* a, int n, int t)
{
	int i = 0, j = 0, sum = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (a[i] + a[j] == t && a[i] != a[j])//找到两个不同的数，满足它们的和等于目标数t
			{
				cout << a[i] << "+" << a[j] << "=" << t << endl;
				sum++;//记录找到满足条件的数对的个数
			}
			j++;
		}
		i++;
		j = i;
	}
	if (sum == 0)//如果找不到满足条件的数对
	{
		cout << "找不到这样的整数" << endl; //输出无法找到满足条件的数对的提示信息
	}
}

// O(nlogn) 算法求解两数之和等于目标值的情况
void target_sum_nlogn(int* a, int n, int t)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = t - a[i];//计算目标数t与当前数a[i]的差值tmp
		int re = Binary_Search(a, n, tmp);;//在数组a中二分查找是否有值等于tmp的元素，返回该元素的下标re
		if (re == -1)//如果数组a中不存在值等于tmp的元素
		{
			continue;//继续查找下一个数
		}
		if (i != re)//如果找到了不同的两个数，使它们的和等于目标数t
		{
			cout << a[i] << "+" << a[re] << "=" << t << endl; //输出这两个数及它们的和
			sum++;//记录找到满足条件的数对的个数
		}
	}
	if (sum == 0)//如果找不到满足条件的数对
	{
		cout << "找不到这样的整数" << endl; //输出无法找到满足条件的数对的提示信息
	}
}

// O(n) 算法求解两数之和等于目标值的情况
void target_sum_n(int* a, int n, int t)
{
	int i = 0, j = n - 1;//i和j分别表示数组a的第一个和最后一个元素的下标
	int sum = 0; //用于记录满足条件的数对的个数
	while (i != j)//当i和j没有相遇
	{
		if (a[i] + a[j] < t) //如果当前两个数的和小于目标数t
		{
			i++;//向右移动i指针，使当前两个数的和增加
		}
		if (a[i] + a[j] > t) //如果当前两个数的和大于目标数t
		{
			j--;//向左移动j指针，使当前两个数的和减小
		}
		if (a[i] + a[j] == t)//如果找到了不同的两个数，使它们的和等于目标数t
		{
			cout << a[i] << "+" << a[j] << "=" << t << endl;//输出这两个数及它们的和
			i++, j--;//向左向右移动指针j、i
			sum++;//记录找到满足条件的数对的个数
		}
	}
	if (sum == 0)//如果找不到满足条件的数对
	{
		cout << "找不到这样的整数" << endl; //输出无法找到满足条件的数对的提示信息
	}
}

int main()
{
	cout << "请输入整数的个数n=";
	int n = 0;
	cin >> n;
	int* a = new int[n];
	cout << "请依次输入该数组元素";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "请输入待求和整数T=";
	int T = 0;
	cin >> T;

	// 计时并调用 O(n^2) 算法
	clock_t start_time_nn = clock();
	target_sum_nn(a, n, T);
	clock_t end_time_nn = clock();
	cout << "O(n^2)算法所用的时间为" << double(static_cast<double>(end_time_nn - start_time_nn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// 计时并调用 O(nlogn) 算法
	clock_t start_time_nlogn = clock();
	target_sum_nlogn(a, n, T);
	clock_t end_time_nlogn = clock();
	cout << "O(nlogn)算法所用时间为" << double(static_cast<double>(end_time_nlogn - start_time_nlogn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;
	
	// 计时并调用 O(n) 算法
	clock_t start_time_n = clock();
	target_sum_n(a, n, T);
	clock_t end_time_n = clock();
	cout << "O(n)算法所用时间为" << double(static_cast<double>(end_time_n - start_time_n) / CLOCKS_PER_SEC * double(1000)) << "ms";
	return 0;
}