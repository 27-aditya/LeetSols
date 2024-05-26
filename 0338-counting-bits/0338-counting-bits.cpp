class Solution {
private:
    void bit(int n, vector<int>&res){
        int cnt = 0;
        while(n > 0){
            int num = n&1;
            if(num == 1)
                cnt++;
            n = n>>1;
        }    
        res.push_back(cnt);
    }
public:
    vector<int> countBits(int n) {
        vector<int>res;
        for(int i = 0; i <= n; i++){
            bit(i, res);
        }
        return res;
    }
};