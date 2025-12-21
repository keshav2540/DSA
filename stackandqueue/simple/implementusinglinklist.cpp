#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int a)
    {
        data = a;
        next = nullptr;
    }
};
class mystack
{
    node *top = nullptr;
    int size = 0;

public:
    void push(int a)
    {
        if (size == 0)
        {
            node *newnode = new node(a);
            top = newnode;
            size++;
        }
        else
        {
            node *newnode = new node(a);
            newnode->next = top;
            top = newnode;
            size++;
        }
    }
    void pop()
    {
        node *temp = top;
        top = top->next;
        size--;
        delete temp;
    }
    int topy()
    {
        return top->data;
    }
    int sizey()
    {
        return size;
    }
};
class myqueue
{ public:
    node *st = nullptr;
    node *end = nullptr;
    int size = 0;
    void push(int a)
    {
        if (size == 0)
        {
            node *newnode = new node(a);
            st = newnode;
            end = newnode;
            size++;
        }
        else
        {
            size++;
            node *newnode = new node(a);
            st->next = newnode;
            st = newnode;
        }
    }
    void pop()
    {
        if (size == 1)
        {
            node *st = nullptr;
            node *end = nullptr;
            size--;
        }
        else
        {size--;
            node*temp=end;
            end=end->next;
            delete temp;  
        }
    }
    int topy(){
        return end->data;
    }
    int sizey(){
        return size;
    }

};

int main()
{
    mystack s;
    s.push(2);
    cout << s.topy() << endl;
    s.push(3);
    cout << s.topy() << endl;
    cout << s.sizey() << endl;
    s.push(4);
    cout << s.sizey() << endl;
    cout << s.topy() << endl;
    s.pop();
    cout << s.sizey() << endl;
    cout << s.topy() << endl;
    s.pop();
    cout << s.sizey() << endl;
    cout << s.topy() << endl;
    return 0;
}
