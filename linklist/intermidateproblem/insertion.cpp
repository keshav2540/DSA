#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
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
Node *convertArrayToLinkList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < 4; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void printLinklist(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
Node *inserthead(Node *head, int val)
{
    Node *newnode = new Node(val);
    Node *temp = head;
    head = newnode;
    newnode->next = temp;
    return head;
}
Node *inserttail(Node *head,int val)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *newnode = new Node(val);
    Node *temp = head;
    while (temp->next != nullptr) temp = temp->next;
     temp->next=newnode;
    temp->next->next = nullptr;
    return head;
}
Node *insertNth(Node *head, int k,int val)
{
    if (head == nullptr)
        return head=new Node(val);
    if (k == 1)
        return inserthead(head,val);
    int count = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        { Node *newnode = new Node(val);
            prev->next=newnode;
            newnode->next=temp;
            break;
        }
        if(temp->next==nullptr) return inserttail(head,val);
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node*insertbeforeEl(Node*head,int val,int el){
if (head == nullptr)
        return head=new Node(val);
    if (head->data == el)
        return inserthead(head,val);
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data== el)
        { Node *newnode = new Node(val);
            prev->next=newnode;
            newnode->next=temp;
            break;
        }
        if(temp->next==nullptr) return inserttail(head,val);
        prev = temp;
        temp = temp->next;
    }
    return head;
    
}

int main()
{
    vector<int> arr = {2, 1, 3, 8};
    Node *head = convertArrayToLinkList(arr);
    printLinklist(head);
    head = insertbeforeEl(head,4, 10);
    printLinklist(head);
    return 0;
}
