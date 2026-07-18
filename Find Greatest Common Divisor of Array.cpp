class Solution {
    public:
        int findGCD(vector<int>& nums) {
            int mine=1001, maxe=-1;
            for(auto &it:nums){
                mine = min(mine, it);
                maxe = max(maxe, it);
            }
            return gcd(mine, maxe);
        }
    };