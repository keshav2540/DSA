#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
node *createlinklist(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *newnode = new node(arr[i]);
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " <==> ";
        temp = temp->next;
    }
}
void deletealloccurance(node*&head,int key){
    node*temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
       if(temp==head){
       head=head->next;
       }
        node *nextnode=temp->next;
        node *prevnode=temp->prev;
        if(nextnode)nextnode->prev=prevnode;
        if(prevnode)prevnode->next=nextnode;
        delete temp;
        temp=nextnode;}
    else {
        temp=temp->next;
    }  }
    return ;
}
int main()
{
    vector<int> nums1 = {10,4,10,10,10,6,10};
    node *head = createlinklist(nums1);
    deletealloccurance(head,10);
    cout << head->data;
    cout << head->next->data;
    // cout << head->next->next->data;
    // cout << head->next->next->next->data;
    // cout << head->next->next->next->next->data;
    // cout << head->next->next->next->next->next->data;
    // cout << head->next->next->next->next->next->next->data;
    // cout << head->next->next->next->next->next->next->next->data;
}
