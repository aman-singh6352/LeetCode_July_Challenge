class Solution {
    public:
        int minimumPushes(string word) {
            int count = 0, ans = 0;
            for(int i = 0;i < word.size();i++){
                if(i%8 == 0) count++;
                ans += count;
            }
            return ans;
        }
    };

/*---------------------------------- JAVA CODE ------------------------------*/
class Solution {
    public int minimumPushes(String word) {
        int count = 0, ans = 0;
        for(int i = 0;i < word.length();i++){
            if(i%8 == 0) count++;
            ans += count;
        }
        return ans;
    }
}