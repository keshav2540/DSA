#include <bits/stdc++.h>
using namespace std;
int give(vector<int>child,vector<int>demand){
    sort(child.begin(),child.end());
    sort(demand.begin(),demand.end());
  int c=0,d=0,count=0;
  while(d<demand.size()){
    if(child[c]<=demand[d]){ count++;
    c++;
    d++;
  } else {
    d++;
  }
} return count;}

int main() {
    vector<int>child={1,3,3,4,5};
    vector<int>demand={4,2,1,2,1,3};
    cout<<give(child,demand);
    return 0;
}