#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    int key;
    node *next;
    node *prev;
    node(int key,int val)
    {   this ->key=key;
        this->data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUcache{
    map<int,node*>maps;
    int capacity;
    node*head=nullptr;
    node*tail=nullptr;
 void inserthead(node*temp)
{
   node*afterhead=head->next;
   head->next=temp;
    temp->prev=head;
     temp->next=afterhead;
   afterhead->prev=temp;
  
}
void deletenode(node *n)
{
    node*nexti= n->next;
    node*previ=n->prev;
    previ->next=nexti;
    nexti->prev=previ;
} 
public:
    LRUcache(int capacity){
        this->capacity=capacity;
        maps.clear();
         head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key){
        if(maps.find(key)==maps.end()) return -1;
        node*temp=maps[key];
        deletenode(temp);
        inserthead(temp);
        cout<<temp->data<<endl;
         return temp->data;
       
    }
    void put(int key,int val){
        if(maps.find(key)!=maps.end()){
            node*temp=maps[key];
            temp->data=val;
            deletenode(temp);
             inserthead(temp);
        }
        else {
            if(maps.size()>=capacity){
               node*temp=tail->prev;
               deletenode(temp);  
               maps.erase(temp->key);
               delete temp;}
               node*newnode=new node(key,val);
               maps[key]=newnode;
               inserthead(newnode);
        }

    }
     void printCache() {
        node *temp = head->next;
        cout << "Cache state: ";
        while (temp != tail) {
            cout << "[" << temp->key << ":" << temp->data << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LRUcache l(4);
    l.put(2,6);
    l.printCache();
    l.put(4,7);
    l.printCache();
    l.put(8,11);
    l.printCache();
    l.put(7,10);
    l.printCache();
     l.get(2);
    l.printCache();
    l.get(8);
    l.printCache();
    l.put(5,6);
    l.printCache();
    l.get(7);
    l.printCache();
    l.put(5,7);
    l.printCache();
    
 
    return 0;
}