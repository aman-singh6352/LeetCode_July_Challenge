class Solution {
    public:
        string smallestSubsequence(string s) {
            string ans;
            vector<int> vis(26, 0), lastIdx(26, 0);
            for(int i = 0;i < s.size();i++) lastIdx[s[i]-'a'] = i;
            for(int i = 0;i < s.size();i++){
                if(vis[s[i]-'a']) continue;
                while(ans.size() && lastIdx[ans.back()-'a'] > i && ans.back() > s[i]){
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                vis[s[i]-'a'] = 1;
            }
            return ans;
        }
    };