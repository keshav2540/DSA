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
node* evenoddlinklist(node*head){
    vector<int>nums;
    node*temp=head;
    while( temp!=nullptr){
        nums.push_back(temp->data);
        if(temp->next==nullptr) break;
        temp=temp->next->next;
    }
    temp=head->next;
    while(temp!=nullptr){
        nums.push_back(temp->data);
        if(temp->next==nullptr) break;
        temp=temp->next->next;
    }
    temp=head; int i=0;
    while(temp!=nullptr){
        temp->data=nums[i++];
        temp=temp->next;
    } return head;
}
node* evenoddlinklist2(node*head){
    node*even=head;
    node*odd=head->next;
    node*oddhead=odd;
    while(odd && odd->next){
            even->next=even->next->next;
            even=even->next;
            odd->next=odd->next->next;
            odd=odd->next;
        } odd->next=nullptr;
        even->next=oddhead;
      return head;
}
int main() {
    vector<int>arr={1,3,4,2,5,6};
    node*head=createlinklist(arr);
    print(evenoddlinklist2(head));

    return 0;
}