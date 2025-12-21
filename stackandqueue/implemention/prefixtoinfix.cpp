#include <bits/stdc++.h>
using namespace std;
string prefixtoinfix(string s)
{
    int i = s.size()-1;
    stack<string> st;
    while (i >= 0)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(s.substr(i, 1));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t1 + s.substr(i, 1) + t2 + ")");
        }
        i--;
    }
    return st.top();
}

int main()
{ string s="*+pq-mn";
    cout<<prefixtoinfix(s);
    return 0;
}