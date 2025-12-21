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
bool ispalindrome(node *head)
{ // using stack;
    if (head == nullptr || head->next == nullptr)
        return 1;
    stack<int> s;
    node *temp = head;
    while (temp != nullptr)
    {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (temp->data != s.top())
            return 0;
        s.pop();
        temp = temp->next;
    }
    return 1;
}

node *is(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
   
    node *second = slow->next;
    slow->next = nullptr;
    node *temp = second;
    node *prv = nullptr;
    while (temp != nullptr)
    {
        node *last = temp->next;
        temp->next = prv;
        prv = temp;
        temp = last;
    }
    slow->next = prv;
    return head;
}
bool ispalinderome2(node *head)
{     is(head);
     node *slow = head;
    node *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node*temp=slow->next;
    while(temp!=nullptr){
        if(temp->data!=head->data) return 0;
        temp=temp->next;
        head=head->next;
    }
    return 1;
}
int main()
{
    vector<int> arr = {1, 2, 3,3, 2, 1};
    node *head = createlinklist(arr);
    cout << ispalinderome2(head)<<endl;
    print(is(head));
    // cout<<ispalindrome(head);
    return 0;
}