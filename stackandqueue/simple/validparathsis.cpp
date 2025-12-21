#include <bits/stdc++.h>
using namespace std;
bool valid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if (!st.empty())
        {
            if ((s[i] == ')' && st.top() == '(') ||
                (s[i] == ']' && st.top() == '[') ||
                (s[i] == '}' && st.top() == '{'))
            {
                st.pop();
            }
            else
                return false;
        }
        else
        {
            return 0;
        }
    }
    return st.empty();
}
int main()
{
    string s = "(((()";
    cout << valid(s);
    return 0;
}
