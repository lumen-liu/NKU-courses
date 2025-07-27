#include<iostream>

using namespace std;
void Merge(int *v1, int l1,int *v2, int l2,int *&result)
{
	if (l1 == 0)
	{
		result = v2;
	}
	else if (l2 == 0)
	{
		result = v1;
	}
	else
	{
		int i = 0, j = 0, k = 0;
		while (i < l1 && j < l2)
		{
			while (v1[i] < v2[j] && i < l1)
			{
				result[k]=v1[i];
				i++;
				k++;
			}
			while (v1[i] >= v2[j] && j < l2)
			{
				result[k] = v2[j];
				j++;
				k++;
			}
		}
		while (i < l1)
		{
			result[k] = v1[i];
			i++;
			k++;
		}
		while (j < l2)
		{
			result[k] = v2[j];
			j++;
			k++;
		}
	}
	
}
int main()
{
	int l1, l2;
	cin >> l1 >> l2;
	int* v1 = new int[l1];
	int* v2 = new int[l2];
	for (int i = 0; i < l1; i++)
	{
		int a = 0;
		cin >> a;
		v1[i] = a;
	}
	for (int i = 0; i < l2; i++)
	{
		int a = 0;
		cin >> a;
		v2[i] = a;
	}
	int *result=new int [l1+l2];
	Merge(v1, l1,v2,l2, result);
	for (int i = 0; i < l1+l2; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}