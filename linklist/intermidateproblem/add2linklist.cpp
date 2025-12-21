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
node *addLinkList(node *head1, node *head2)
{
    int sum ,carry = 0;
    node *dumy = new node(-1);
    node *temp = dumy;
    while (head1 != nullptr || head2 != nullptr)
    {
        sum = carry;
       if(head1!=nullptr) sum += head1->data;
       if(head2!=nullptr) sum += head2->data;
        node *newnode = new node(sum % 10);
        carry = sum / 10;
        temp->next = newnode;
        temp = newnode;
        if (head1 != nullptr)
            head1 = head1->next;
        if (head2 != nullptr)
            head2 = head2->next;
    }
    if (carry != 0)
    {
        node *newnode = new node(carry);
        temp->next = newnode;
    }
    return dumy->next;
}

int main()
{
    vector<int> nums1 = {2,4,6};
    vector<int> nums2 = {3,8,7};
    node *head1 = createlinklist(nums1);
    // print(head1);
    cout << endl;
    node *head2 = createlinklist(nums2);
    // print(head2);
    print(addLinkList(head1, head2));
    return 0;
}