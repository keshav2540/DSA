#include <bits/stdc++.h>
using namespace std;
class data{
    public:
    int val,wet;
    data(int val,int wet){
        this->wet=wet;
        this->val=val;
    }
};
bool compare(data a,data b){
    return (a.val/a.wet)>(b.val/b.wet);
}
int sol(vector<data>&arr,int weight){int sum=0;
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++){
        if(weight>=arr[i].wet){
            sum+=arr[i].val;
            weight-=arr[i].wet;
        }
        else{
            sum+=((double)arr[i].val/(double)arr[i].wet)*weight;
         break;
        }
    } return  sum;

}
int main() {
    vector<data>arr={{100,20},{60,10},{100,50},{200,50}};
    cout<<sol(arr,90);
    return 0;
}