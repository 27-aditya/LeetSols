class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        double result;
        if(nums1.size()%2 == 0){
            int n1 = nums1[nums1.size()/2-1];
            int n2 = nums1[nums1.size()/2];
            result = (double)(n1+n2)/2;
        }
        else{
            result = (double)nums1[nums1.size()/2];
            cout << result << endl;
        }
        return result;
    }
};