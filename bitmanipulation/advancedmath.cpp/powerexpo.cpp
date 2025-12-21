#include <bits/stdc++.h>
using namespace std;
double power(double x, int  n)
{
    double ans = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ans = ans * x;
            n = n - 1;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}

int main()
{
    cout << power(2.5, 3); return 0;
}