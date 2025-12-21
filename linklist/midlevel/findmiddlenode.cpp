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
node*slowfastmethold(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    return slow;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4,5};
    node *head = createlinklist(nums1);
    node *temp = head;
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
    print(head);
    cout<<endl;
     cout<<slowfastmethold(head)->data;
}
