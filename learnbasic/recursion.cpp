#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int n)
{
    if (n == 0)
        return; // normal code
    cout << n << " hello " << endl;
    print(n - 1);
}
void printf(int i, int n)
{
    if (i > n)
        return;
    printf(i, n - 1); // backtracking
    cout << n << "n ";
}
int sumfirstN(int n)
{
    if (n == 0)
        return 0;
    return n + sumfirstN(n - 1); // functional
}
int sumfrtN(int i, int sum = 0)
{
    if (i == 0)
        return sum;
    sumfrtN(i - 1, sum + i); // parateraised
}
long int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}
void reverseARRAy(int arr[], int i)
{
    int n = 5;
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseARRAy(arr, i + 1);
}
bool checkpalindrome(string num, int i)
{
    int n = num.size();
    if (n - i - 1 <= i)
        return true;
    if (num[i] != num[n - i - 1])
        return false;
    return checkpalindrome(num, i + 1);
}
long int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;
    long int last = fibo(n - 1);
    long int secondlast = fibo(n - 2);
    return last + secondlast;
}

int main()
{
    // print(4);
    // printf(1,5);
    // cout<<factorial(5);
    // int arr[]={5,4,32,45,13};
    //  reverseARRAy(arr,0);
    //  for(int i:arr)cout<<i<<endl;
    cout << checkpalindrome("123456789987654321", 0);
    cout << endl
         << fibo(6);
    return 0;
}