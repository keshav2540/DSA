// we can use hashing concept node,frq;
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *child;
    node(int data)
    {
        this->data = data;
        next = nullptr;
        child = nullptr;
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
        temp = temp->child;
    }
}
node*mergesort(node*head1,node*head2){
    node*head=new node(-1);
    node*temp=head;
    node*temp1=head1;
    node*temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data<temp2->data){
            temp->child=temp1;
            temp=temp->child;
            temp1=temp1->child;
        }
        else{
             temp->child=temp2;
            temp=temp->child;
            temp2=temp2->child;
        }}
        if(temp1) temp->child=temp1;
        if(temp2) temp->child=temp2;
     return head->child;
   
}
node*flatternlist(node*head){
    if(head==nullptr||head->next==nullptr) return head;
    node*mergehead=flatternlist(head->next);
      return mergesort(head,mergehead);
}
int main()
{
    vector<int> nums1 = {3,2,1,4,5};
    node *head = createlinklist(nums1);
    head->next->child=new node(10);
    head->next->next->child=new node(7);
    head->next->next->child->child=new node(11);
    head->next->next->child->child->child=new node(12);
     head->next->next->next->child=new node(9);
    head->next->child=new node(10);
    head->next->next->next->next->child=new node(6);
    head->next->next->next->next->child->child=new node(8);
print(flatternlist(head));}