#include <bits/stdc++.h>
using namespace std;
int myatoi(string s, int &st, int &ans, bool &sign)
{
    if (st >=s.size())return sign ? ans : -ans;
    if (st == 0 && (s[st] == ' '||s[st]=='+'||s[st]=='-'))
       { while (st<s.size()&&s[st] == ' ')st++;
         if (st<s.size() && s[st] == '+' || s[st] == '-'){
          if (s[st] == '-') sign = 0;
           st++;}}
   if (st<s.size() && s[st] >= '0' && s[st] <= '9')
          {  ans = ans * 10 + (s[st++] - '0');
            return  myatoi(s, st, ans, sign);}
     else
            return ans;}
   
int ansmy(string s)
{
    int st = 0, ans = 0;bool sign = 1;
    return myatoi(s, st, ans, sign);
}

int main()
{     string s="23456789abc";
    cout<<ansmy(s);

    return 0;
}