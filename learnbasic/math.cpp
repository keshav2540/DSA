#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int count(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int reverse(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}
bool palingram(int n)
{
    if (n == reverse(n))
        return true;
    else
        return false;
}
bool armstrong(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans = ans + ((n % 10) * (n % 10) * (n % 10));
        n /= 10;
    }
    return ans == n;
}

void printalldivision(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            cout << " " << i << " " << n / i;
    }
}
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n == 1 && n == 2)
            return true;
        if (n % i == 0)
            return false;
    }
    return true;
}
int GCD(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 >= n2)
            n1 %= n2;
        else
            n2 %= n1;
    }
    if (n1 == 0)
        return n2;
    if (n2 == 0)
        return n1;
    // for(int n=min(n1,n2);n>0;n--)if(n1%n==0&&n2%n==0) return n;;
}

int HCF(int n1, int n2)
{
    return min(n1, n2) / GCD(n1, n2);
}
int main()
{
    cout << count(1233) << endl;
    cout << reverse(123);
    cout << endl
         << palingram(1266821);
    cout << endl
         << armstrong(370) << endl;
    printalldivision(36);
    cout << endl
         << isprime(9);
    cout << endl
         << GCD(15, 20);
    cout << endl
         << HCF(15, 20);
    return 0;
}