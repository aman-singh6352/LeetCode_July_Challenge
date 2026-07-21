class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            s.push_back('1');
            s.insert(s.begin(), '1');
            vector<int> blockOfZeros;
            int cnt = 0, cntOnes = 0;
            for(int i = 1;i < s.size();){
                if(s[i] == '0') {
                    cnt++;
                    i++;
                }
                else {
                    if(cnt != 0) blockOfZeros.push_back(cnt);
                    cnt = 0;
                    while(i < s.size() && s[i] == '1') cntOnes++, i++;
                }
            }
            int maxpairsum = 0;
            for(int i = 1;i < blockOfZeros.size();i++){
                maxpairsum = max(maxpairsum, blockOfZeros[i] + blockOfZeros[i-1]);
            }
            return cntOnes + maxpairsum-1;
        }
    };

// Removing Extra Space

class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            s.push_back('1');
            int curr = 0, cntOnes = 0, maxpairsum = 0, prev = 0;
            for(int i = 0;i < s.size();){
                if(s[i] == '0') {
                    curr++;
                    i++;
                }
                else {
                    if(prev != 0) {
                        maxpairsum = max(maxpairsum, curr + prev);
                    }
                    prev = curr;
                    curr = 0;
                    while(i < s.size() && s[i] == '1') cntOnes++, i++;
                }
            }
            return cntOnes + maxpairsum-1;
        }
    };


// ---------------------------- JAVA CODE ---------------------------------//

class Solution {
    public int maxActiveSectionsAfterTrade(String s) {
        s += '1';
        int curr = 0, cntOnes = 0, maxpairsum = 0, prev = 0, n = s.length();
        for(int i = 0;i < n;){
            if(s.charAt(i) == '0') {
                curr++;
                i++;
            }
            else {
                if(prev != 0) {
                    maxpairsum = Math.max(maxpairsum, curr + prev);
                }
                prev = curr;
                curr = 0;
                while(i < n && s.charAt(i) == '1') {
                    cntOnes++;
                    i++;
                }
            }
        }
        return cntOnes + maxpairsum-1;
    }
}