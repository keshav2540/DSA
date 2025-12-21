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
node*reverserecursive(node*head){
    if(head==nullptr||head->next==nullptr) return head;
    node*newhead= reverserecursive(head->next);
    node*front=head->next;
    front->next=head;
    head->next=nullptr;
   return newhead;
    }
node*add1(node*head){
   node*head1= reverserecursive(head);
     int carry=1;
     node*temp=head1;
     node*prev=nullptr;
   while(temp!=nullptr){
    temp->data=temp->data+carry;
    if(temp->data==10){
        temp->data=0;
        carry=1;
    }
    else{carry=0;}
    prev=temp;
    temp=temp->next;
   } if(carry==1){
    node*newnode=new node(1);
    prev->next=newnode;
    newnode->next=0; 
    return reverserecursive(head1);
   }    return reverserecursive(head1);
}
 int helper(node*head){
    node*temp=head;
    if(temp==nullptr) return 1;
     int carry= helper(temp->next);
     temp->data=temp->data+ carry;
     if(temp->data>=10){
        temp->data=0;
         return 1;
     }else return 0;
 }
 node*add1recursively(node*head){
    int carry=helper(head);
    if(carry==1){
     node*newnode=new node(1);
     newnode->next=head;
     head=newnode;
        return head;
    }
    return head;
}
int main() { vector<int> nums1 = {1,2,3,4,5,6};
    node *head1 = createlinklist(nums1);
    // print(head1);
    cout<<endl;
    print(add1recursively(head1));
    return 0;
}