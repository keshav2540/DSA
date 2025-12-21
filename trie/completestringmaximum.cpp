#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
    node *child[26];
    bool fl;
    node()
    {
        fl = false;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
    bool containkey(char key)
    {
        return (child[key - 'a'] != nullptr);
    }
    void put(char ch, node *node)
    {
        child[ch - 'a'] = node;
    }
    node *get(char ch)
    {
        return child[ch - 'a'];
    }
    void setend()
    {
        fl = true;
    }
    bool isend()
    {
        return fl;
    }
};
class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }
    void insert(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!curr->containkey(s[i]))
            {
                curr->put(s[i], new node());
            }
            curr = curr->get(s[i]);
        }
        curr->setend();
    }
    bool checkperfixexist(string s)
    {
        node *curr = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (curr->containkey(s[i]))
            {
                curr = curr->get(s[i]);
                if (curr->isend() == false)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
    string completestring(int n, vector<string> &v)
    {
        trie t;
        for (auto i : v)
            t.insert(i);
        string longest = "";
        for (string &it : v)
        {
            if (t.checkperfixexist(it))
            {
                if (it.size() > longest.size())
                {
                    longest = it;
                }

                else if (it.size() == longest.size() && it < longest)
                {
                    longest = it;
                }
            }
        } return longest;
    }
};
int main()
{
    vector<string> v = {"n", "ninja", "ninj", "nin", "ninga", "ni"};
    trie t;
    cout << t.completestring(6, v);
    return 0;
}