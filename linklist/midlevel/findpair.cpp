// we can use hashing concept node,frq;
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
    }}
//map methold 
//twopointer
vector<pair<int,int>>pairsum(node*head,int sum){
    vector<pair<int,int>>ans;
    node*tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    while(head!=tail){
        if(head->data+tail->data==sum){
            ans.push_back({head->data,tail->data});
           head=head->next;
        }
        else if(sum<head->data+tail->data){
            tail=tail->prev;
        }
        else head=head->next;
    }
  return ans;
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
    for(auto i:pairsum(head,5)) cout<<i.first<<" "<<i.second<<endl;
}
