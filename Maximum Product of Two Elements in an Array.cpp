class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int maxe = 0, secmaxe = 0;
            for(int i = 0;i < nums.size();i++){
                if(nums[i] > maxe) {
                    secmaxe = maxe;
                    maxe = nums[i];
                }
                else if(secmaxe < nums[i]){
                    secmaxe = nums[i];
                }
            }
            return (maxe-1) * (secmaxe-1);
    ;    }
    };

/*---------------------------- JAVA CODE ----------------------------*/
class Solution {
    public int maxProduct(int[] nums) {
        int maxe = 0, secmaxe = 0;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] > maxe) {
                secmaxe = maxe;
                maxe = nums[i];
            }
            else if(secmaxe < nums[i]){
                secmaxe = nums[i];
            }
        }
        return (maxe-1) * (secmaxe-1);
    }
}