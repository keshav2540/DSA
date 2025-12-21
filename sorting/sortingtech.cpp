#include <bits/stdc++.h>
using namespace std;
void insertionsort(vector<int> &num)
{
    int n = num.size();
    for (int i = 1; i < n; i++)
    {
        while (n > i && i >= 0 && num[i] < num[i - 1])
        {
            swap(num[i], num[i - 1]);
            i--;
        }
    }
}
void selectionsort(vector<int> &num)
{
    int n = num.size();
    for (int i = 0; i < n; i++)
    {
        int minidx = n, minx = INT32_MAX;
        for (int j = i; j < n; j++)
        {
            if (num[j] < minx)
            {
                minx = num[j];
                minidx = j;
            }
        }
        swap(num[i], num[minidx]);
    }
}
void bubblesort(vector<int> &num)
{
    int n = num.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (num[j] < num[j - 1])
            {
                swap(num[j], num[j - 1]);
            }
        }
    }
}
void merge(vector<int> &num, int st, int mid, int end)
{
    vector<int> temp;
    int left = st;
    int right = mid + 1;
    while (left <= mid && right <= end)
    {
        if (num[left] < num[right])
        {
            temp.push_back(num[left]);
            left++;
        }
        else
        {
            temp.push_back(num[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(num[left]);
        left++;
    }
    while (right <= end)
    {
        temp.push_back(num[right]);
        right++;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        num[st++] = temp[i];
    }
};
void mergesort(vector<int> &num, int st, int end)
{
    if (st == end)
        return;
    int mid = (st + end) / 2;
    mergesort(num, st, mid);
    mergesort(num, mid + 1, end);
    merge(num, st, mid, end);
}
void display(vector<int> &num)
{
    for (int i : num)
        cout << i << endl;
}
int Pivotidx(vector<int> &num, int st, int end)
{
    int pivot = num[st];
    int low = st + 1, high = end;
    while (low <= high)
    {
        while (low <= end && num[low] <= pivot)
        {
            low++;
        }
        while (low <= high && num[high] > pivot)
        {
            high--;
        }
        if (low < high)
            swap(num[low], num[high]);
    }
    swap(num[st], num[high]);
    return high;
}

void Quicksort(vector<int> &num, int st, int end)
{
    if (st < end)
    {
        int pivotidx = Pivotidx(num, st, end);
        Quicksort(num, st, pivotidx - 1);
        Quicksort(num, pivotidx + 1, end);
    }
}
int main()
{
    vector<int> num = {1, 9, 8, 7, 6, 5, 4, 8765};
    int n = num.size() - 1;
    Quicksort(num, 0, n);
    display(num);
    return 0;
}