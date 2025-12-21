// we can use hashing concept node,frq;
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
void removedulicate(node*head){
    node*temp=head; node*nextnode=temp->next;
    while(temp!=nullptr){
        while(nextnode!=nullptr &&temp->data==nextnode->data){
            node*hello=nextnode;
            nextnode=nextnode->next;
            delete hello;
        }
        temp->next=nextnode;
    if(nextnode)nextnode->prev=temp;
        temp=nextnode;
     if(nextnode)nextnode=nextnode->next;
    }
}
int main()
{
    vector<int> nums1 = {1, 1,1, 3,3,4,4,4 , 5,6, 6,};
    node *head = createlinklist(nums1);
    // node *temp = head;
    // while (temp->next != nullptr)
    // {
    //     temp = temp->next;
    // }
    // temp->next = head->next->next;
    // cout << head->data;
    // cout << head->next->data;
    // cout << head->next->next->data;
    // cout << head->next->next->next->data;
    // cout << head->next->next->next->next->data;
    // cout << head->next->next->next->next->next->data;
    // cout << head->next->next->next->next->next->next->data;
    // cout << head->next->next->next->next->next->next->next->data;
    removedulicate(head);
    print(head);
}
