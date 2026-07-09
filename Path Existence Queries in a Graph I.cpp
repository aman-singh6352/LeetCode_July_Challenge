class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> connected(n);
        int groupId = 0;
        connected[0] = groupId;
        for(int i = 1;i < n;i++){
            if(abs(nums[i]-nums[i-1]) > maxDiff) groupId++;
            connected[i] = groupId;
        }
        vector<bool> ans;
        for(auto it:queries){
            ans.push_back(connected[it[0]] == connected[it[1]]);
        }
        return ans;
    }
};