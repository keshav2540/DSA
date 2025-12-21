#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    string data;
    node *next;
    node *prev;
    node(string data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
class browser{
    public:
      node*current=nullptr;
      browser(string homepage){
        current=new node(homepage);
      }
      void visit(string s){
        node*newnode=new node(s);
        current->next=newnode;
        newnode->prev=current;
        current=current->next;
      }
      string back(int step){
        while(step&& current->prev!=nullptr){
            current=current->prev;
            step--;
        }
        if(current) return current->data;
      }
      string forward(int step){
        while(step&& current->next!=nullptr){
            current=current->next;
            step--;
        }
        if(current) return current->data;
      }
};
int main()
{    browser b("hello goggle");
     b.visit("insta");
    b.visit("facebook");
    b.visit("gemini");
    cout<<b.back(3)<<endl;
    cout<<b.forward(1)<<endl;
}
