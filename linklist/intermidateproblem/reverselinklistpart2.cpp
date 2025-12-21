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
node*reverserecursive(node*head){
    if(head==nullptr||head->next==nullptr) return head;
    node*newhead= reverserecursive(head->next);
    node*front=head->next;
    front->next=head;
    head->next=nullptr;
   return newhead;
    }
int main() { vector<int> nums1 = {2,4,6,7,8};
    node *head1 = createlinklist(nums1);
    // print(head1);
    cout<<endl;
    print(reverserecursive(head1));
    return 0;
}