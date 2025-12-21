#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>findseqence(string startword,string targetword,vector<string>wordlist){
  
unordered_set<string>st(wordlist.begin(),wordlist.end());
    queue<vector<string>>q;
    q.push({startword});
    vector<string>usedlevel;
    usedlevel.push_back(startword);
    int level=0;
    vector<vector<string>>ans;
    while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>level){
            level++;
            for(auto it:usedlevel){
                st.erase(it);
            }usedlevel.clear();
        }
        string word=vec.back();
        if(word==targetword){
            if(ans.size()==0){
                ans.push_back(vec);
            }
           else if(ans[0].size()==vec.size()){
                ans.push_back(vec);
            }
        }
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.count(word)>0)
               {  vec.push_back(word);
                q.push(vec);
                usedlevel.push_back(word);
                vec.pop_back();
            }
            } word[i]=original;
        }
    }
 return ans;
}
int main() {
    vector<string>wordlist={"hot","dot","dog","lot","log","cog"};
string startnode="hit";
string target="cog";
for(auto &i:findseqence(startnode,target,wordlist)){
    for(auto j:i){
        cout<<j<<" -> ";
    }cout<<endl;
}
    return 0;
}