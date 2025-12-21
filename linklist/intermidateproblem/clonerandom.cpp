#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *random;
    node(int data)
    {
        this->data = data;
        next = nullptr;
        random= nullptr;
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
        cout << temp->data <<", ";
        if(temp->random) cout<<temp->random->data;
        cout<<"==>";
        temp = temp->next;
    }
}
node*clone(node*head){node*temp=head;
    while(temp!=nullptr){
        node*newnode=new node(temp->data);
         newnode->next=temp->next;
         temp->next=newnode;
        temp=newnode->next;
    }temp=head;
    while(temp!=nullptr){
      if(temp->random){
        temp->next->random= temp->random->next;}
        temp=temp->next->next;
    } 
    node*dummy=new node(-1);
    node*copy=dummy;
    temp=head;
    while(temp!=nullptr){
        copy->next=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        copy=copy->next;
    }  return dummy->next;
}
     
int main() {
    vector<int>arr={7,13,11,10,1};
    node*head=createlinklist(arr);
    head->random=head->next->next->next->next;
    head->next->random=head;
    head->next->next->random=head;
    head->next->next->next->random=head->next->next->next->next;
    head->next->next->next->next->random=head->next->next;
     print(head);
     cout<<endl<<head;
     cout<<endl;
     print(clone(head));
      cout<<endl<<clone(head);

    return 0;
}