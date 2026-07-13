class Solution {
    public:
        vector<int> sequentialDigits(int low, int high) {
            vector<int> mp(10), add(9);
            mp[2] = 12; mp[3] = 123; mp[4] = 1234;
            mp[5] = 12345; mp[6] = 123456; mp[7] = 1234567; mp[8] = 12345678;
            mp[9] = 123456789;
    
            add[2] = 11; add[3] = 111; add[4] = 1111;
            add[5] = 11111; add[6] = 111111; add[7] = 1111111; add[8] = 11111111;
    
            int digit = log10(low) + 1, num = mp[digit];
            vector<int> ans;
            while(num <= high){
                if(num >= low) ans.push_back(num);
                if(num == 123456789) break;
                if(num%10 == 9) {
                    num = mp[digit + 1];
                    digit++;
                }
                else num += add[digit];
            }
            return ans;
        }
    };