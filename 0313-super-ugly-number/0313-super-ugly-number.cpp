class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long int> nextMultiple(primes.begin(), primes.end());

        vector<int>multipleOf(primes.size(), 0);

        vector<long long int>ugly(n);
        ugly[0] = 1;
        for(int i = 1; i < n; i++){
            int nextUgly = *min_element(nextMultiple.begin(), nextMultiple.end());
            ugly[i] = nextUgly;

            for(int j = 0; j < primes.size(); j++){
                if(nextUgly == nextMultiple[j]){
                    multipleOf[j]++;
                    nextMultiple[j] = ugly[multipleOf[j]]*primes[j];
                }
            }
        }

        return ugly[n-1];
    }
};