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
void printreverse(node *head)
{
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        cout << temp->data << " <==> ";
        temp = temp->prev;
    }
}
node*reverse(node*head){// in term of data
   stack<int>s;
   node *temp = head;
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
       temp->data =s.top();
       s.pop();
        temp = temp->next;
    } return  head;
}
node*reversereal(node*head){
    node *temp = head;
    node*last=nullptr;
    while (temp!= nullptr)
    {  last=temp->prev; 
        temp->prev=temp->next;
        temp->next=last;
      temp=temp->prev;
    }
    if(last!=nullptr) head=last->prev;
     return head;
}
int main() { vector<int> nums1 = {2,4,6,7,8};
    node *head1 = createlinklist(nums1);
    // print(head1);
    cout<<endl;
    print(reversereal(head1));
    return 0;
}