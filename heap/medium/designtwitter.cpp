#include <bits/stdc++.h>
using namespace std;
class twitter{
    int timestamp=0;
    unordered_map<int,unordered_set<int>>follows;// set of follower
    unordered_map<int,vector<pair<int,int>>>tweets;// tweets pair with time
    public:
     void posttweet(int userid ,int tweetid){
        tweets[userid].push_back({timestamp++,tweetid});
     }
     vector<int>getnews(int userid){
        priority_queue<pair<int,int>>maxheap;// for sort according to time
        vector<int>result;
        follows[userid].insert(userid);
        for(auto follower:follows[userid]){
            auto &tw=tweets[follower];
             for(auto i:tw){
                maxheap.push(i);
             }
        }
        int count=0;
        while(!maxheap.empty()&& count<10){
            result.push_back(maxheap.top().second);
            maxheap.pop();
            count++;
        } 
        return result;
     }
     void follow(int followerid,int followid ){
        if(followerid==followid) return;
        follows[followerid].insert(followid);
     }
     void unfollow(int followerid,int followid ){
        if(followerid==followid) return;
         follows[followerid].erase(followid);
     }

};
int main() {

    return 0;
}