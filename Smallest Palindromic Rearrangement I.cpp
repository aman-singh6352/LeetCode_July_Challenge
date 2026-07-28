class Solution {
    public:
        string smallestPalindrome(string s) {
            vector<int> hash(26, 0);
            for(auto &it:s){
                hash[it-'a']++;
            }
            string ans = s;
            int i = 0, j = s.size()-1;
            while(i <= j){
                for(int k = 0;k < 26;k++){
                    if(hash[k] > 1) {
                        ans[i] = ans[j] = k + 'a';
                        hash[k] -= 2;
                        break;
                    }
                    if(i == j && hash[k]) {
                        ans[i] = k+'a';
                        break;
                    } 
                }
                i++;
                j--;
            }
            return ans;
        }
    };

/*------------------------- JAVA CODE -----------------------*/

class Solution {
    public String smallestPalindrome(String s) {
        int[] hash = new int[26];
            for(char it:s.toCharArray()){
                hash[it-'a']++;
            }
            StringBuilder ans = new StringBuilder(s);
            int i = 0, j = s.length()-1;
            while(i <= j){
                for(int k = 0;k < 26;k++){
                    if(hash[k] > 1) {
                        ans.setCharAt(i, (char)(k + 'a'));
                        ans.setCharAt(j, (char)(k + 'a'));
                        hash[k] -= 2;
                        break;
                    }
                    if(i == j && hash[k] != 0) {
                        ans.setCharAt(i, (char)(k + 'a'));
                        break;
                    } 
                }
                i++;
                j--;
            }
            return ans.toString();
    }
}