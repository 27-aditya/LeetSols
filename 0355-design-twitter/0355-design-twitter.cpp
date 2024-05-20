class Twitter {
private:
    unordered_map<int, vector<pair<int,int>>>dbt;
    unordered_map<int, vector<int>>dbf;
    int timestamp;
public:
    Twitter() {   
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        dbt[userId].emplace_back(tweetId, timestamp);
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        int cnt = 0;
        priority_queue<pair<int,int>>pq;
        
        for(auto tweet: dbt[userId])
            pq.push({tweet.second, tweet.first});

        for(auto userid : dbf[userId]){
            for(auto tweet : dbt[userid]){
                pq.push({tweet.second, tweet.first});
            }
        }
        vector<int>result;
        while(!pq.empty() && cnt < 10){
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
            
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(find(dbf[followerId].begin(),dbf[followerId].end(), followeeId) == dbf[followerId].end())
        dbf[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            if(find(dbf[followerId].begin(), dbf[followerId].end(), followeeId) != dbf[followerId].end())
            dbf[followerId].erase(find(dbf[followerId].begin(), dbf[followerId].end(), followeeId));
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */