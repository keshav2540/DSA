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
node*removenodeback(node*head,int k){
       // count method;
       node*temp=head;
       node*prev=nullptr;
       int count =0;
      while(temp!=nullptr){
        count++;
        temp=temp->next;
      }  
       int a=count-k+1;
      count=0;
      temp=head;
     while(temp!=nullptr) {
      count++;
    if(a==count){
        prev->next=prev->next->next;
        free(temp);
        break;
    }
    prev=temp;
     temp=temp->next;}
    return head;
}
node*removenodebackslowfastpointer(node*head,int k){
    node*slow=head;
    node*fast=head;
     while(k!=0){
        fast=fast->next;
        k--;
     }
     while(fast->next!=nullptr){
        fast=fast->next;
        slow=slow->next;
     } 
     fast=slow->next;
     slow->next=slow->next->next;
     delete fast;
     return head;
}
     
int main() {
    vector<int>arr={1,2,3,4,5};
    node*head=createlinklist(arr);
    print(removenodebackslowfastpointer(head,2));
    return 0;
}