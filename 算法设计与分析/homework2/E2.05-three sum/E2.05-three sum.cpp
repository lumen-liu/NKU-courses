#include<iostream>
#include<time.h> 
#include"Binary Search.h" // 导入二分查找函数头文件
using namespace std;

// O(n^3) 算法求解两数之和等于目标值的情况
void target_sum_nnn(int* a, int n, int t)
{
	int i = 0, j = 0, k = 0, sum = 0;
	while (k < n)
	{
		while (i < n)
		{
			while (j < n)
			{
				if (a[i] + a[j] +a[k] == t && a[i] != a[j] && a[i] != a[k])//找到三个不同的数，满足它们的和等于目标数t
				{
					cout << a[k] << "+" << a[i] << "+" << a[j] << "=" << t << endl;
					sum++;//记录找到满足条件的数对的个数
				}
				j++;
			}
			i++;
			j = i;
		}
		k++;
		i = k;
	}
	if (sum == 0)//如果找不到满足条件的数对
	{
		cout << "找不到这样的整数" << endl; //输出无法找到满足条件的数对的提示信息
	}
}

// O(n^2*logn) 算法求解两数之和等于目标值的情况
void target_sum_nnlogn(int* a, int n, int t)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int tmp = t - a[i] - a[j];//计算目标数t与当前数a[i]、a[j]的差值tmp
			int re = Binary_Search(a, n,tmp); //在数组a中二分查找是否有值等于tmp的元素，返回该元素的下标re
			if (re == -1)//如果数组a中不存在值等于tmp的元素
			{
				continue;//继续查找下一个数
			}
			if (i != re && i != j && re > j)//如果找到了不同的两个数，使它们的和等于目标数t
			{
				cout << a[i] << "+" << a[j] << "+" << a[re] << "=" << t << endl; //输出这两个数及它们的和
				sum++;//记录找到满足条件的数对的个数
			}
		}
	}
	if (sum == 0)//如果找不到满足条件的数对
	{
		cout << "找不到这样的整数" << endl; //输出无法找到满足条件的数对的提示信息
	}
}

// O(n^2) 算法求解两数之和等于目标值的情况
void target_sum_nn(int* a, int n, int t)
{
	int i = 0, j = i + 1, k = n - 1;
	int sum = 0;
	for (i; i < n - 3; i++)
	{
		j = i + 1;
		while(j != k)
		{
			if (a[i] + a[j] + a[k] < t) //如果当前三个数的和小于目标数t
			{
				j++;//向右移动j指针，使当前三个数的和增加
			}
			if (a[i] + a[j] + a[k] > t) //如果当前三个数的和大于目标数t
			{
				k--;//向左移动j指针，使当前三个数的和减小
			}
			if (a[i] + a[j] + a[k] == t)//如果找到了不同的两个数，使它们的和等于目标数t-a[i]
			{
				cout << a[i] << "+" << a[j] << "+" << a[k] << "=" << t << endl;//输出这三个数及它们的和
				j++;
				sum++;//记录找到满足条件的数对的个数
			}
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

	// 计时并调用 O(n^3) 算法
	clock_t start_time_nnn = clock();
	target_sum_nnn(a, n, T);
	clock_t end_time_nnn = clock();
	cout << "O(n^3)算法所用的时间为" << double(static_cast<double>(end_time_nnn - start_time_nnn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// 计时并调用 O(n^2*logn) 算法
	clock_t start_time_nnlogn = clock();
	target_sum_nnlogn(a, n, T);
	clock_t end_time_nnlogn = clock();
	cout << "O(n^2*logn)算法所用时间为" << double(static_cast<double>(end_time_nnlogn - start_time_nnlogn) / CLOCKS_PER_SEC * double(1000)) << "ms" << endl;

	// 计时并调用 O(n^2) 算法
	clock_t start_time_nn = clock();
	target_sum_nn(a, n, T);
	clock_t end_time_nn = clock();
	cout << "O(n^2)算法所用时间为" << double(static_cast<double>(end_time_nn - start_time_nn) / CLOCKS_PER_SEC * double(1000)) << "ms";
	return 0;
}