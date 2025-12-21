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
    }
}
auto compare=[](pair<node*,int>p,pair<node*,int>q){
    return p.second>q.second;
};
node*mergesort(vector<node*>nums){
    priority_queue<pair<node*,int>,vector<pair<node*,int>>,decltype(compare)>pq(compare);
    for(auto i:nums)pq.push({i,i->data});
    node*head=new node(-1);
     node*temp=head;
    while(!pq.empty()){
        pair<node*,int>p=pq.top();pq.pop();
        temp->next=p.first;
        temp=temp->next;
       if(p.first->next) pq.push({p.first->next,p.first->next->data});
    } return head->next;
}
int main()
{
    vector<int> nums1 = {2,4,6};
    vector<int> nums2 = {1,5};
    vector<int> nums3 = {1,1,3,7};
    node *head1 = createlinklist(nums1);
    node *head2= createlinklist(nums2);
    node *head3= createlinklist(nums3);
    vector<node*>nums={head1,head2,head3};
print(mergesort(nums));}