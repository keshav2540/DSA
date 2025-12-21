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
node*merge(node*head1,node*head2){
    node*head=new node(-1);
    node*temp=head;
    node*temp1=head1;
    node*temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<temp2->data){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        else{
             temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }}
        if(temp1) temp->next=temp1;
        if(temp2) temp->next=temp2;
     return head->next;
   
}
node*findmiddle(node*head){
    node*slow=head;
    node*fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    return slow;
}
node*mergesort(node*head){
    if(head==nullptr||head->next==nullptr) return head;
    node*middle=findmiddle(head);
    node*left=head;
    node*right=middle->next;
    middle->next=nullptr;
    node*lefthead=mergesort(left);
    node*righthead=mergesort(right);
    return merge(lefthead,righthead);
}
int main()
{
    
    vector<int> nums2 = {1,3,10,6,7,8,9,11,14};
    node *head= createlinklist(nums2);
      print(mergesort(head));
}