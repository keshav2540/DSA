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
    cout<<endl;
}
Node*deletehead(Node*head){
    Node*temp=head;
    head=temp->next;
    delete temp;
    return head;
}
Node*deleteNth(Node*head,int k){
    if(head==nullptr)return head;
    if(k==1)return deletehead(head);
    int count=0;
    Node*temp=head;Node*prev=nullptr;
    while(temp!=nullptr) {
      count++;
    if(count ==k){
        prev->next=prev->next->next;
        free(temp);
        break;
    }
    prev=temp;
     temp=temp->next;}
    return head;
}
Node*deletetail(Node*head){
    if(head==nullptr||head->next==nullptr)return nullptr;
    Node*temp=head;
    while(temp->next->next!=nullptr) temp=temp->next;
    delete temp->next;
    temp->next=nullptr;
    return head;
}
int main() {
    vector<int >arr={2,1,3,8};
    Node*head=convertArrayToLinkList(arr);
    printLinklist(head);
    head=deleteNth(head,2);
    printLinklist(head);
    return 0;
}