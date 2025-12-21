
     void push(int a){
        int l=q.size();
        q.push(a);
        for(int i=1;i<=l;i++){
            q.push(q.front());
            q.pop();
        }
     }
     void pop(){
        q.pop();
     }
     int topy(){
        return q.front();
     }
     int sizey(){
        return q.size();
     }
};
class myqueue{public:
     stack<int>s1;
     stack<int>s2;
     void push(int a){
       while(s1.size()){
        s2.push(s1.top());
        s1.pop();