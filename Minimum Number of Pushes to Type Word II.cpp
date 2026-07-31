class Solution {
    public:
        int minimumPushes(string word) {
            int uniq = 0, count = 0, ans = 0;
            vector<int> freq(26, 0);
            for(auto &it:word) freq[it-'a']++;
            sort(begin(word), end(word), [&](char a, char b){
                return freq[a-'a'] > freq[b-'a'];
            });
            vector<int> mp(26, 0);
            for(int i = 0;i < word.size();i++){
                if(mp[word[i]-'a'] != 0) ans += mp[word[i]-'a'];
                else {
                    uniq++;
                    if(uniq%8 == 1) count++;
                    mp[word[i]-'a'] = count;
                    ans += count;
                }
            }
            return ans;
        }
    };

/* -------------------------- Optimised -------------------------*/
class Solution {
    public:
        int minimumPushes(string word) {
            vector<int> freq(26);
            for(auto &it:word){
                freq[it-'a']++;
            }
            sort(begin(freq), end(freq), greater<int>());
            int count = 0, ans = 0;
            for(int i = 0;i < freq.size();i++){
                if(i%8 == 0) count++;
                ans += freq[i] * count;
            }
            return ans;
        }
    };

/* ---------------------------------- JAVA CODE ----------------------------*/
class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for (char ch : word.toCharArray()) {
            freq[ch - 'a']++;
        }
        Arrays.sort(freq);
        for (int i = 0; i < 13; i++) {
            int temp = freq[i];
            freq[i] = freq[25 - i];
            freq[25 - i] = temp;
        }
        int count = 0, ans = 0;
        for (int i = 0; i < freq.length; i++) {
            if (i % 8 == 0)
                count++;
            if (freq[i] > 0)
                ans += freq[i] * count;
        }
        return ans;
    }
}