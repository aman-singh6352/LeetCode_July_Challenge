/*----------------------------- BRUTE FORCE -----------------------------*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(auto &it:nums) cout << it << " ";
        if(nums[n-1] < 0) return min(nums[0] * nums[1], nums[n-2] * nums[n-3]) * nums[n-1];
        return max(nums[0] * nums[1], nums[n-2] * nums[n-3]) * nums[n-1];
    }
};

/*------------------------------ THOUGHT PROCESS -------------------------*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxe = *max_element(begin(nums), end(nums));
        if(maxe == 0) return 0;
        if(maxe < 0){
            // i need two smallest elements not maxe // two small * maxe
        }

        if(maxe > 0) {
            // two case 
            // 1
            // i need two negative smallest elements not maxe// two small * maxe
            // i need two positive elements not maxe// two big * maxe
            
            // 2
            // or may be a condition that one positive and one negative
            // in this case one negative greater and one positive greater
            // two big * maxe
        }
    }
};

/*------------------------------ OPTIMAL CODE ----------------------------*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1001, max2 = -1999, max3 = -1999, min1 = 1001, min2 = 1001;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3) {
                max3 = nums[i];
            }

            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2) {
                min2 = nums[i];
            }
        }

        // either (max1 * max2 * max3)  or (max1 * max2 * max3)
        return max(max1*max2*max3, min1*min2*max1);
    }
};

/*------------------------------ JAVA CODE -------------------------------*/
class Solution {
    public int maximumProduct(int[] nums) {
        int max1 = -1001, max2 = -1999, max3 = -1999, min1 = 1001, min2 = 1001;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3) {
                max3 = nums[i];
            }

            if(nums[i] < min1) {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2) {
                min2 = nums[i];
            }
        }
        // either (max1 * max2 * max3)  or (max1 * max2 * max3)
        return Math.max(max1*max2*max3, min1*min2*max1);
    }
}