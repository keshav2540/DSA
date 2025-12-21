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
void merge(node *head1, node *head2)
{
    node *temp = head2;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = head1->next->next->next->next;
    print(head1);
    cout << endl;
    print(head2);
    cout<<endl;
}
int commomnode(node*head1,node*head2){
    merge(head1,head2);
    map<node*,int>s;
    node*temp=head1;
    while(temp!=nullptr){
        s[temp]++;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=nullptr){
        if(s.find(temp)!=s.end()){
            return temp->data; }
                temp=temp->next;
    } return 0;
}

int colisionpoint(node*head1,node*head2,int diff){
    node*temp1=head1;
    while(diff!=0&& temp1!=nullptr){
        diff--;
        temp1=temp1->next;
    }
    node*temp2=head2;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1==temp2) return temp1->data;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 0;
}
int finddis(node*head1,node*head2){
     merge(head1,head2);
    node*temp1=head1;
    node*temp2=head2;
    int n1=0,n2=0;
    while(temp1!=nullptr || temp2!=nullptr){
        if(temp1!=nullptr){
            n1++;
            temp1=temp1->next;
        }
       if(temp2!=nullptr){
        n2++;
        temp2=temp2->next;
       }
    }
    if(n1>=n2){
        return colisionpoint(head1,head2,n1-n2);
    }
    else{
        return colisionpoint(head2,head1,n2-n1);
    }
}
int optimal(node*head1,node*head2){
    if(head1==nullptr||head2==nullptr) return 0;
    merge(head1,head2);
    node*temp1=head1;
    node*temp2=head2;
    // while(temp1!=nullptr && temp2!=nullptr){
    //     temp1=temp1->next;
    //     temp2=temp2->next;
    // }
    // if(temp1==nullptr) temp1=head2;
    // if(temp2==nullptr) temp2=head1;
    // while(temp1!=nullptr && temp2!=nullptr){
    //     temp1=temp1->next;
    //     temp2=temp2->next;
    // }
    // if(temp1==nullptr) temp1=head2;
    // if(temp2==nullptr) temp2=head1;

    // while(temp1!=nullptr && temp2!=nullptr){
    //     if(temp1==temp2) return temp1->data;
    //     temp1=temp1->next;
    //     temp2=temp2->next;
    // } 
    while(temp1!=temp2){
        temp1=temp1->next;
      temp2=temp2->next;
      if(temp1==temp2) return temp1->data;
   if(temp1==nullptr) temp1=head2;
  if(temp2==nullptr) temp2=head1;
    }   
    return 0;

}
 int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
    node *head1 = createlinklist(nums1);
    vector<int> nums2 = {9,  7, 6, 8, 0};
    node *head2 = createlinklist(nums2);
    cout<<optimal(head1, head2);
    return 0;
}