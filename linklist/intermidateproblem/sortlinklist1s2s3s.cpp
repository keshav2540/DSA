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
node*sortusingcount(node*head){
int count1=0;
int count2=0;
int count0=0;
node*temp=head;
while(temp!=nullptr){
    if(temp->data==1)count1++;
   else if(temp->data==2)count2++;
    else count0++;
    temp=temp->next;
}
cout<<count0<<count1<<count2<<endl;
temp=head;
while(count0!=0){
  temp->data=0;
  temp=temp->next;
  count0--;
}
while(count1!=0){
  temp->data=1;
  temp=temp->next;
  count1--;
}
while(count2!=0){
  temp->data=2;
  temp=temp->next;
  count2--;
} return head;
}

node*sortanotherlist(node*head){
    node*temp=head;
    node*dum0=new node(-1);
    node*temp0=dum0;
    node*dum1=new node(-1);
    node*temp1=dum1;
    node*dum2=new node(-1);
    node*temp2=dum2;
    while(temp!=nullptr){
        if(temp->data==0){
           temp0->next=temp;
           temp0=temp0->next;
        }
        else if(temp->data==1){
            temp1->next=temp;
            temp1=temp1->next;
        }
     else {
            temp2->next=temp;
            temp2=temp2->next;
        }
        temp=temp->next;
    } temp0->next=dum1->next? dum1->next:dum2->next;
      temp1->next=dum2->next;
      temp2->next=nullptr;
      head=dum0->next;
     delete dum0;
     delete dum1;
     delete dum2;
     return head;
}
int main() {
    vector<int>arr={1,0,1,2,0,2,1};
    node*head=createlinklist(arr);
    print(sortanotherlist(head));

    return 0;
}