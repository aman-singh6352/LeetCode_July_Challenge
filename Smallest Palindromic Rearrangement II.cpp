class Solution {
    private:
        long long nCr(int n, int r, long long cap){
            long long ans = 1;
            for(int i = 1; i <= r; i++){
                ans = ans * (n - r + i) / i;
                if(ans >= cap) return cap;
            }
            return ans;
        }
    public:
        string smallestPalindrome(string s, int k) {
            int n = s.size();
            vector<int> count(26, 0);
            int totalpos = n/2;
            for(int i = 0;i < n/2;i++) count[s[i]-'a']++;
            long long totalways = 1;
            for(int i = 0;i < 26;i++){
                if(count[i] > 0){
                    totalways *= nCr(totalpos, count[i], k);
                    totalpos -= count[i];
                }
                if(totalways >= k) break;
            }
            string halfstr;
            if(totalways < k) return halfstr;
            for(int i = 0;i < n/2;i++){
                for(int j = 0;j < 26;j++){
                    if(count[j] > 0){
                        count[j]--;
                        int rempos = n/2 - halfstr.size()-1;
                        long long ways = 1;
                        for(int c = 0;c < 26;c++){
                            if(count[c] > 0) {
                                ways *= nCr(rempos, count[c], k);
                                rempos -= count[c];
                                if(ways >= k || rempos < 0) break;
                            }
                        }
                        if(ways < k) k -= ways;
                        else {
                            halfstr.push_back(j + 'a');
                            break;
                        }
                        count[j]++;
                    }
                }
            }
            if(n%2 == 1) halfstr.push_back(s[n/2]);
            for(int i = n/2-1;i >= 0;i--){
                halfstr.push_back(halfstr[i]);
            }
            return halfstr;
        }
    };

/* ------------------------------- JAVA CODE -----------------------------------*/

class Solution {
    static long nCr(int n, int r, long cap){
            long ans = 1;
            for(int i = 1; i <= r; i++){
                ans = ans * (n - r + i) / i;
                if(ans >= cap) return cap;
            }
            return ans;
    }
    public String smallestPalindrome(String s, int k) {
        int n = s.length();
        int[] count = new int[26];
        int totalpos = n/2;
        for(int i = 0;i < n/2;i++) count[s.charAt(i)-'a']++;
        long totalways = 1;
        for(int i = 0;i < 26;i++){
            if(count[i] > 0){
                totalways *= nCr(totalpos, count[i], k);
                totalpos -= count[i];
            }
            if(totalways >= k) break;
        }
        StringBuilder halfstr = new StringBuilder();
        if(totalways < k) return "";
        for(int i = 0;i < n/2;i++){
            for(int j = 0;j < 26;j++){
                if(count[j] > 0){
                    count[j]--;
                    int rempos = n/2 - halfstr.length()-1;
                    long ways = 1;
                    for(int c = 0;c < 26;c++){
                        if(count[c] > 0) {
                            ways *= nCr(rempos, count[c], k);
                            rempos -= count[c];
                            if(ways >= k || rempos < 0) break;
                        }
                    }
                    if(ways < k) k -= ways;
                    else {
                        halfstr.append((char)(j + 'a'));
                        break;
                    }
                    count[j]++;
                }
            }
        }
        if(n%2 == 1) halfstr.append(s.charAt(n/2));
        for(int i = n/2-1;i >= 0;i--){
            halfstr.append(halfstr.charAt(i));
        }
        return halfstr.toString();
    }
}