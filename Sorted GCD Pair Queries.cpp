class Solution {
    public:
        vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
            int maxe = *max_element(begin(nums), end(nums)), n = nums.size();
            vector<long long> factorCnt(maxe+1, 0);
            for(int i = 0;i < n;i++){
                int val = nums[i];
                for (long long ele = 1; ele * ele <= val; ele++) {
                    if (val % ele == 0) {
                        factorCnt[ele]++;
                        long long pair = val / ele;
                        if (pair != ele) {
                            factorCnt[pair]++;
                        }
                    }
                }
            }
    
            // storing the possible pairs
            // and removing the extra ones
            for(int i = maxe;i > 0;i--){
                factorCnt[i] = factorCnt[i]*(factorCnt[i]-1)/2;
                int  k = 2, multiple = i*k;
                while(multiple <= maxe){
                    factorCnt[i] -= factorCnt[multiple];
                    k++;
                    multiple = i * k;
                }
            }
    
            // cummulative prefixCnt
            for(int i = 1;i <= maxe;i++) {
                factorCnt[i] += factorCnt[i-1];
            }
    
            vector<int> ans;
            for(auto it:queries){
                // binary search lower bound
                int idx = upper_bound(begin(factorCnt), end(factorCnt), it) - begin(factorCnt);
                ans.push_back(idx);
            }
            return ans;
        }
    };