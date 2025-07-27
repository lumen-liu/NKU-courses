int Binary_Search(int* a, int n, int x)
{
    int length = n;
    int left = 0, right = length - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        if (a[mid] > x)
        {
            right = mid - 1;
        }
    }
    return -1;
}