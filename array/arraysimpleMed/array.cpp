#include <bits/stdc++.h>
using namespace std;

int largestarray1(vector<int> &arr)
{
   int n = arr.size();
   sort(arr.begin(), arr.end());
   return arr[n - 1];
}
int largestarray2(vector<int> &arr)
{
   int n = arr.size();
   int largest = INT32_MIN;
   for (int i : arr)
      largest = max(largest, i);
   return largest;
}
int seclargestarray1(vector<int> &arr)
{
   int n = arr.size();
   int largest = arr[0], second;
   for (int i : arr)
      if (i > largest)
      {
         second = largest;
         largest = i;
      }
   return second;
}
int seclargestarray2(vector<int> &arr)
{
   int n = arr.size();
   sort(arr.begin(), arr.end());
   while (arr[n - 1] == arr[n - 2])
   {
      n--;
   }
   return arr[n - 2];
}
void removeduplicate(vector<int> &arr)
{
   int n = arr.size();
   set<int> s;
   for (int i = 0; i < n; i++)
      s.insert(arr[i]);
   for (auto i : s)
      cout << i << " ";
}
vector<int> unin(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
   int i = 0, j = 0;
   sort(arr1.begin(), arr1.end());
   sort(arr2.begin(), arr2.end());
   vector<int> temp;
   while (i < n1 && j < n2)
   {
      while (arr1[i] == arr1[i + 1] && i < n1)
         i++;
      while (arr2[j] == arr2[j + 1] && j < n2)
         j++;
      if (arr1[i] < arr2[j])
      {
         temp.push_back(arr1[i]);
         i++;
      }
      else if (arr1[i] == arr2[j])
      {
         temp.push_back(arr1[i]);
         i++;
         j++;
      }
      else
      {
         temp.push_back(arr2[j]);
         j++;
      }
   }
   while (i < n1)
   {
      while (arr1[i] == arr1[i + 1] && i < n1)
         i++;
      while (arr2[j] == arr2[j + 1] && j < n2)
         j++;
      temp.push_back(arr1[i]);
      i++;
   }
   while (j < n2)
   {
      while (arr1[i] == arr1[i + 1] && i < n1)
         i++;
      while (arr2[j] == arr2[j + 1] && j < n2)
         j++;
      temp.push_back(arr2[j]);
      j++;
   }
   return temp;
}
vector<int> intersec(vector<int> &arr1, vector<int> &arr2, int n1, int n2)
{
   int i = 0, j = 0;
   sort(arr1.begin(), arr1.end());
   sort(arr2.begin(), arr2.end());
   vector<int> temp;
   while (i < n1 && j < n2)
   {
      while (arr1[i] == arr1[i + 1] && i < n1)
         i++;
      while (arr2[j] == arr2[j + 1] && j < n2)
         j++;
      if (arr1[i] > arr2[j])
         j++;
      else if (arr1[i] < arr2[j])
         i++;
      else
      {
         temp.push_back(arr1[1]);
         i++;
         j++;
      }
   }
   return temp;
}
void nextperm(vector<int> &num)
{
   int n = num.size();
   int i = -1;
   for (i = n - 2; i >= 0; i--)
   {
      if (num[i] < num[i + 1])
      {
         break;
      }
   }
   
   if (i == -1)
   {
      reverse(num.begin(), num.end());
      return;
   }
   for (int j = n - 1; j > i; j--)
   {
      if (num[i] < num[j])
      {
         swap(num[i], num[j]);
         break;
      }
   }
   reverse(num.begin() + i + 1, num.end());
   //    while ((i + 1) <= (n - 1))
   //    {
   //       swap(num[i + 1], num[n - 1]);
   //       i++;
   //       n--;
   //    }
}
vector<int> leaderarr(vector<int> &num)
{
   vector<int> res;
   int n = num.size() - 1;
   int max = INT32_MIN;
   for (int i = n; i >= 0; i--)
   {
      if (num[i] > max)
      {
         res.push_back(num[i]);
         max = num[i];
      }
   }
   reverse(res.begin(), res.end());
   return res;
}

int main()
{
   // vector<int> arr1 = {1, 2, 3, 4, 1, 34, 35};
   // vector<int> arr2 = {34, 87, 1};
   // int n1 = arr1.size();
   // int n2 = arr2.size();
   // vector<int> temp = intersec(arr1, arr2, n1, n2);
   // for (int i : temp)
   // {
   //    cout << i << endl;
   // }
   // vector<int> arr = {6, 554, 3, 5, 2, 5, 6, 2, 45, 3325, 3325};
   // // cout<< seclargestarray2(arr);
   // removeduplicate(arr);
   // return 0;
   vector<int> num = {10, 22, 12, 3, 0, 6};
   leaderarr(num);
   for (int i : leaderarr(num))
      cout << i << " ";
   // vector<int> num = {2, 1, 5, 4, 3, 0, 0};
   // nextperm(num);
   // for (int i : num)
   //    cout << i;
}