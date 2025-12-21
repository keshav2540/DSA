#include <bits/stdc++.h>
using namespace std;
struct node
{
public:
    node *bit[2]={nullptr};
    bool containkey(int key){
        return (bit[key]!=nullptr);
    }
    node*get(int key){
        return bit[key];
    }
    void put(int key,node*nod){
        bit[key]=nod;
    }
};
class trie{
    public:
    node*root;
    trie(){
        root=new node();
    }
    void insert(int num){
        node*temp=root;
        for(int i=31;i>=0;i--){
            int bits=(num>>i)&1;
            if(!temp->containkey(bits)){
                temp->put(bits,new node());
            }
        temp=temp->get(bits);
        }
    }
      public :
       int getmax(int num){
        node*temp=root;
        int maxnum=0;
         for(int i=31;i>=0;i--){
            int bits=(num>>i)&1;
            if(temp->containkey(1-bits)){
                maxnum=maxnum|(1<<i);
                temp=temp->get(1-bits);
            }
            else{
                  temp=temp->get(bits); 
            }
         } return maxnum;
       }

     int maxxor(int m,int n,int arr[],int arr2[]){
        trie t;
        for(int i=0;i<n;i++) t.insert(arr[i]);
        int maximum=0;
        for(int i=0;i<m;i++){
        maximum=max(maximum,t.getmax(arr2[i]));
        }
           return maximum;
     }
     };

int main() {
 int arr[5]={9,8,5,4};
 int arr2[3]={1,2,7};
 trie t;
 cout<<t.maxxor(3,5,arr,arr2);
    return 0;
}