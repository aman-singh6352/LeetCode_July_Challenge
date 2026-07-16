class Solution {
    public:
        long long gcdSum(vector<int>& nums) {
            vector<int> prefixGcd;
            int mx = -1;
            for(auto &it:nums){
                mx = max(mx, it);
                prefixGcd.push_back(gcd(mx, it));
            }
            sort(prefixGcd.begin(), prefixGcd.end());
            int i = 0, j = nums.size()-1;
            long long sum = 0;
            while(i < j){
                sum += gcd(prefixGcd[i], prefixGcd[j]);
                i++;
                j--;
            }
            return sum;
        }
    };