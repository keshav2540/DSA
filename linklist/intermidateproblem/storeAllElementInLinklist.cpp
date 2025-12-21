#include <bits/stdc++.h>
using namespace std;
class Node
{public:
    int data;
    Node *next;
    Node(int DATA, Node *NEXT)
    {
        data = DATA;
        next = NEXT;
    }
    Node(int DATA)
    {
        data = DATA;
        next = nullptr;
    }

};
Node*convertArrayToLinkList(vector<int>&arr){
    Node*head=new Node(arr[0]);
     Node*mover=head;
     for(int i=1;i<4;i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
     } return head;
}
void printLinklist(Node*head){
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
}

int main() {
    vector<int >arr={2,1,3,8};
    printLinklist(convertArrayToLinkList(arr));
    return 0;
}