class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            unordered_map<int, int> hash;
            unordered_set<int> ans;
            int n = nums.size();
            for(int i = 0;i < n;i++){
                for(int j = i;j < n;j++){
                    hash[nums[i]^nums[j]] = j;
                }
            }
            for(auto &it:hash){
                for(int i = it.second;i < n;i++){
                    ans.insert(it.first^nums[i]);
                }
            }
            return ans.size();
        }
    };

/* ------------------------------------ JAVA CODE ------------------------------------------*/

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        Map<Integer, Integer> hash = new HashMap<>();
        Set<Integer> ans = new HashSet<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                hash.put(nums[i] ^ nums[j], j);
            }
        }

        for (Map.Entry<Integer, Integer> it : hash.entrySet()) {
            int xorVal = it.getKey();
            int startJ = it.getValue();
            for (int i = startJ; i < n; i++) {
                ans.add(xorVal ^ nums[i]);
            }
        }

        return ans.size();
    }
}