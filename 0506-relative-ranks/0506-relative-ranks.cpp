class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedscores(score.begin(), score.end());
        sort(sortedscores.begin(),sortedscores.end(), greater<int>());
        vector<string> result(score.size());
        int j = 0;
        for(int i = 0; i < score.size();i++){
            for(int a = 0;a < score.size();a++){
                if(score[a] == sortedscores[j]){
                    if(j == 0){
                        result[a] = "Gold Medal";
                    }
                    else if(j == 1){
                        result[a] = "Silver Medal";
                    }
                    else if(j == 2){
                        result[a] = "Bronze Medal";
                    }
                    else{ 
                        string r = to_string(j+1);
                        result[a] = r;
                    }
                    break;
                }
            }
            j++;
        }
        return result;
    }
};