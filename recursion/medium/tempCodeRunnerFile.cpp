void generate(int n,string ans,vector<string>&res){
    if(ans.size()==n) {res.push_back(ans);return ;}
    generate(n,ans+"0",res);
    if(ans.empty()|| ans.back()!=1){
        generate(n,ans+'1',res);
    }
 }
int main() {
    vector<string>res;
    int n=3;
    string ans="";
    generate(n,ans,res);
    for(auto i:res)cout<<i<<endl;
    return 0;
}