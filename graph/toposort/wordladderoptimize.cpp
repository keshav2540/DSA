#include <bits/stdc++.h>
using namespace std;
class solution
{
    map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> &seq)
    {
        if (word == b)
        {  reverse(seq.begin(),seq.end());
            ans.push_back(seq);
              reverse(seq.begin(),seq.end());
            return;
        }
        int step = mpp[word];
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == step)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
                word[i] = original;
            }
        }
    }

public:
    vector<vector<string>> findladder(string beginword, string endword, vector<string> &wordlist)
    {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        queue<string> q;
        b = beginword;
        q.push({beginword});
        mpp[beginword] = 1;
        int sz = beginword.size();
        while (!q.empty())
        {
            string word = q.front();
            int step = mpp[word];
            q.pop();
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = step + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endword) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endword);
            dfs(endword, seq);
        }
        return ans;
    }
};
int main()
{
    vector<string> wordlist = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startnode = "hit";
    string target = "cog";
    solution s;
    for (auto &i : s.findladder(startnode, target, wordlist))
    {
        for (auto j : i)
        {
            cout << j << " -> ";
        }
        cout << endl;
    }
    return 0;
}