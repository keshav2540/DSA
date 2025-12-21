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
    for (int i = 1; i < 4; i++)
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
node *inserthead(node *head, int val)
{
    node *newnode = new node(val);
    node *temp = head;
    head = newnode;
    newnode->next = temp;
    temp->prev = newnode;
    return head;
}
node *inserttail(node *head, int val)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    node *newnode = new node(val);
    node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
node *insertNth(node *head, int k, int val)
{
    if (head == nullptr)
        return head = new node(val);
    if (k == 1)
        return inserthead(head, val);
    int count = 0;
    node *temp = head;
    node *back = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            node *newnode = new node(val);
            back->next = newnode;
            newnode->prev = back;
            newnode->next = temp;
            temp->prev = newnode;
            break;
        }
        if (temp->next == nullptr)
            return inserttail(head, val);
        back = temp;
        temp = temp->next;
    }
    return head;
}
node *insertbeforeEl(node *head, int val, int el)
{
    if (head == nullptr)
        return head = new node(val);
    if (head->data == el)
        return inserthead(head, val);
    node *temp = head;
    node *back = nullptr;
    while (temp != nullptr)
    {
        if (temp->data == el)
        {
            node *newnode = new node(val);
            back->next = newnode;
            newnode->prev = back;
            newnode->next = temp;
            temp->prev = newnode;
            break;
        }
        if (temp->next == nullptr)
            return inserttail(head, val);
        back = temp;
        temp = temp->next;
    }
    return head;
}
node *deletehead(node *head)
{
    node *temp = head;
    head = temp->next;
    head->prev = nullptr;
    delete temp;
    return head;
}
node *deletetail(node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    node *temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;
    temp->next->prev = nullptr;
    delete temp->next;
    temp->next = nullptr;
    return head;
}
node *deleteNth(node *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
        return deletehead(head);
    int count = 0;
    node *temp = head;
    node *back = nullptr;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            back->next = back->next->next;
            if (back->next != nullptr)
            {
                back->next->prev = back;
            }
            delete (temp);
            break;
        }
        back = temp;
        temp = temp->next;
        if (temp == nullptr)
            return deletetail(head);
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 1, 3, 8};
    node *head = createlinklist(arr);
    // print(head);
    head = deleteNth(head, 2);
    print(head);
    cout << endl;
    printreverse(head);
    return 0;
}