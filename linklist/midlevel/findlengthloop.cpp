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
int slowfastmetholdfindlength(node*head){
    node*slow=head;
    node*fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    if(slow==fast)
    {int count=1;
        fast=fast->next;
        while(slow!=fast){
            count++;
        fast=fast->next;
    }
return count;}
   cout<<"no cycle";
    return 0;
}
int usingmap(node*head){
    int timer=1;
    map<node*,int>m;
    node*temp=head;
    m[head]=1;
    while(temp!=nullptr){
        ++timer;
        temp=temp->next;
        if(m.find(temp)==m.end()){
            m[temp]=timer;
        }
        else{
            cout<<timer<<endl;
            return( timer-m[temp]);
        }
    }
    cout<<"nocycle";
    return 0;

}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
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
    cout<<usingmap(head)<<" "<<((head->next->next)->data);
}
