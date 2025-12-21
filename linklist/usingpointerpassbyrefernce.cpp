#include <bits/stdc++.h>
using namespace std;
// pointer us addresss par store value ko change kar saktha ye pass by refernce se
// like ham dono me hi a ki value change kar sakte ye but pointer ki value change nhi kar sakte ye to only pass by refernce se hi possible ye
void change1(int *p){
    *p=10;
    p=p+1;
}
void change2(int *&p){
    *p=10;
    p=p+1;
}
int main() {
    int a=20;
    int*p=&a;
    cout<<p<<endl;
    cout<<*p<<endl;
    change1(p); // change only data
    cout<<p<<endl;
    cout<<*p<<endl;
    change2(p);// every thing had changed
    cout<<p<<endl;
    cout<<*(p-1)<<endl;
    cout<<*p<<endl;

    return 0;
}