#include<bits/stdc++.h>
using namespace std;

// 归并排序并计算逆序对的数量
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long count = 0;

    i = left;  // 左半部分的起始下标
    j = mid;   // 右半部分的起始下标
    k = left;  // 合并后数组的起始下标

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            count += (mid - i);  // 计算逆序对的数量
        }
    }

    // 将剩余元素复制到 temp 数组中
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将 temp 数组中的元素复制回 arr 数组中
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return count;
}

// 归并排序
long long merge_sort(int arr[], int temp[], int left, int right) {
    int mid;
    long long count = 0;

    if (right > left) {
        mid = (right + left) / 2;

        // 递归地对左半部分和右半部分进行归并排序
        count += merge_sort(arr, temp, left, mid);
        count += merge_sort(arr, temp, mid + 1, right);

        // 归并左右两个有序子数组并计算逆序对的数量
        count += merge(arr, temp, left, mid + 1, right);
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    // 创建数组并读取输入
    int* arr = new int[n];
    int* temp = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 使用归并排序计算逆序对的数量
    long long count = merge_sort(arr, temp, 0, n - 1);

    // 输出结果
    cout << count << endl;

    return 0;
}
