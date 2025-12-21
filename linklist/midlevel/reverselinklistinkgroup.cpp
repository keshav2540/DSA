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
node *findkthnode(node *temp, int k)
{
    while (k != 1 && temp != nullptr)
    {
        temp = temp->next;
        k--;
    }
    return temp;
}
node *reversereal(node *&head)
{
     node* prev = nullptr;
    node* curr = head;
    while (curr) {
        node* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
    
}

void sol(node *&head, int k)
{
    node *temp = head;
    node *prevnode = nullptr;
    while (temp != nullptr)
    {
        node *kthnode = findkthnode(temp, k);
        if (kthnode == nullptr)
        {
           if(prevnode) prevnode->next = temp;
            break;
        }
        node*nextnode = kthnode->next;
        kthnode->next = nullptr;
        node*newhead=reversereal(temp);
        if (temp == head)
        {
            head = newhead;
        }
        else
        {
            prevnode->next = newhead;
        }
        prevnode = temp;
        temp = nextnode;
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6,4};
    node *head = createlinklist(nums1);
    node *temp = head;
    // sol(head,3);
    sol(head,3);
    print(head);
}
