#include <bits/stdc++.h>
using namespace std;
class Node
{public:
    int data;
    Node *next;
    Node(int DATA, Node *NEXT)
    {
        data = DATA;
        next = NEXT;
    }
    Node(int DATA)
    {
        data = DATA;
        next = nullptr;
    }

};

int
main()
{
    Node *y = new Node(5);
    cout<<y->data<<" "<<y->next;
    return 0;
}