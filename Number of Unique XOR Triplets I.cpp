class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return 1;
            if(n == 2) return 2;
            int i = 0, msbidx;
            // 1 -> n
            while(i < 32){
                if(n & (1 << i)) msbidx = i;
                i++;
            }
            return (1 << ++msbidx);
        }
    };


/* ---------------------------- JAVA CODE -----------------------------------*/

class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int i = 0, msbidx = 0;
        // 1 -> n
        while(i < 32){
            if((n & (1 << i)) != 0) msbidx = i;
            i++;
        }
        return (int)(1 << ++msbidx);
    }
}