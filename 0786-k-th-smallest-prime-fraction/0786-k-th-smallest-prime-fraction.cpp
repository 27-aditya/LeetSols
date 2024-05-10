class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        unordered_map<double, pair<int, int>>calc;
        vector<double>frac;
        int a = 0;
        for(int i =0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                frac.push_back((double)arr[i]/arr[j]);
                calc[(double)arr[i]/arr[j]] = {arr[i],arr[j]};
            }
        }    
        sort(frac.begin(), frac.end());
        vector<int> result(2);
        result[0] = calc[frac[k-1]].first;
        result[1] = calc[frac[k-1]].second;
        return result;
    }
};