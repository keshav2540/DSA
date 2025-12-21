#include <bits/stdc++.h>
using namespace std;
 void expresion(string &num,int target,int st,int currval,int lastoprent,string ex,vector<string>&result){
        if(st==num.size()){
            if(currval==target){
                result.push_back(ex);
            } 
            return ;
        }
        for(int i=st;i<num.size();i++){
            if(num[st]==0&& i>st)break;
            string currnum=num.substr(st,i-st+1);
            long long currnumval=stoll(currnum);// reverse of two string string to number
            if(st==0){
                expresion(num,target,i+1,currnumval,currnumval,currnum,result);
            } 
            else{
                expresion(num,target,i+1,currval+currnumval,currnumval,ex+"+"+currnum,result);

                expresion(num,target,i+1,currval-currnumval,-currnumval,ex+"-"+currnum,result);

                expresion(num,target,i+1,currval-lastoprent+lastoprent*currnumval,currnumval*lastoprent,ex+"*"+currnum,result);
            }

        }
 }

int main() {
string num="123456789";
int target=56;
vector<string>result;
string s="";
expresion(num,target,0,0,0,s,result);
for(auto i:result) cout<<i<<" = "<<target<<endl;
    return 0;
}