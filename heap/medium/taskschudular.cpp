#include <bits/stdc++.h>
using namespace std;
int mintimeintask(vector<string>s,int p){
    int n=s.size();
    unordered_map<string,int>m;
    for(int i=0;i<s.size();i++)m[s[i]]++;
    priority_queue<pair<int,string>>pq;
    for(auto i:m)pq.push({i.second,i.first});
       int frq=pq.top().first;
        int count=0;
    while(!pq.empty() && pq.top().first==frq){  
         pq.pop();
        count++; 
    }
    return max(n,(((frq-1)*(p+1))+count));
}
int main() {
  vector<string>str={"A","A","A","B","B","c"};
  cout<<mintimeintask(str,2);
    return 0;
}