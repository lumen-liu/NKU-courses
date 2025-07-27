#include<bits/stdc++.h>
using namespace std;


// 将两个有序数组合并成一个有序数组
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // 创建临时数组来保存左右两个子数组的值
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // 合并两个子数组
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 处理剩余的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // 递归地将数组分成两个子数组
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        // 合并两个子数组
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;

    // 创建数组并读取输入
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 使用归并排序对数组进行排序
    mergesort(arr, 0, n - 1);

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
