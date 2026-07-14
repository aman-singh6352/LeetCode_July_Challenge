class Solution {
    public:
        long long dp[201][201][201];
        int mod = 1e9+7;
        int solve(int i, int gcd1, int gcd2, vector<int>& nums){
            if(i == nums.size()) {
                if(gcd1 != 0 && gcd1 == gcd2) return 1;
                return 0;
            }
            int temp1 = gcd1, temp2 = gcd2;
            if(dp[i][temp1][temp2] != -1) return dp[i][temp1][temp2];
            // none
            long long none = solve(i+1, gcd1, gcd2, nums);

            // seq1
            if(gcd1 == -1) gcd1 = nums[i];
            else gcd1 = gcd(gcd1, nums[i]);
            long long seq1 = solve(i+1, gcd1, gcd2, nums);

            // seq2
            if(gcd2 == -1) gcd2 = nums[i];
            else gcd2 = gcd(gcd2, nums[i]);
            long long seq2 = solve(i+1, temp1, gcd2, nums);

            return dp[i][temp1][temp2] = (none + seq1 + seq2)%mod;
        }
        int subsequencePairCount(vector<int>& nums) {
            memset(dp, -1, sizeof(dp));
            return solve(0, 0, 0, nums);
        }
    };