class DetectSquares {
private:
    unordered_map<int, unordered_map<int,int>>ds;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        ds[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int result = 0;

        for(auto i = ds.begin(); i != ds.end(); i++){
            unordered_map<int,int>ypoints = i->second;
            for(auto j = ypoints.begin(); j != ypoints.end(); j++){
                int x3 = i->first;
                int y3 = j->first;

                if(x1-x3 == 0 || abs(x1-x3) != abs(y1-y3))
                    continue;

                result += ds[x3][y3]*ds[x1][y3]*ds[x3][y1];
            }
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */