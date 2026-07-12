class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            vector<int> temp(begin(arr), end(arr));
            sort(begin(temp), end(temp));
            int rank = 1, n = arr.size();
            vector<int> ans(n);
            unordered_map<int, int> mp;
            for(int i = 0;i < n;i++){
                if(i > 0 && temp[i] != temp[i-1]) rank++;
                mp[temp[i]] = rank;
            }
            for(int i = 0;i < n;i++){
                ans[i] = mp[arr[i]];
            }
            return ans;
        }
    };

// Optimal 

class Solution {
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            vector<pair<int, int>> temp;
            int n = arr.size();
            for(int i = 0;i < arr.size();i++){
                temp.push_back({arr[i], i});
            }
            sort(temp.begin(), temp.end());
            int rank = 1;
            vector<int> ans(n);
            for(int i = 0;i < n;i++){
                if(i > 0 && temp[i].first != temp[i-1].first) rank++;
                ans[temp[i].second] = rank;
            }
            return ans;
        }
    };