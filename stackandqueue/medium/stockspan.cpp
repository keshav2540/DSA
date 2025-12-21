#include <bits/stdc++.h>
using namespace std;
class stockspanner{
    stack<pair<int,int>>st;
    int idx=-1;
    public:
    stockspanner(){
        idx=-1;
    }
    int next(int a){int ans=0;
        idx++;
        while(!st.empty()&& st.top().first<=a){
            st.pop();
        }
        ans=idx-(st.empty()?-1:st.top().second);
        st.push({a,idx});
        return ans;
    }
};
int main() {
    stockspanner s;
    cout<<s.next(7)<<endl;
    cout<<s.next(2)<<endl;
    cout<<s.next(1)<<endl;
    cout<<s.next(3)<<endl;
    cout<<s.next(3)<<endl;
    cout<<s.next(1)<<endl;
    cout<<s.next(8)<<endl;

    return 0;
}