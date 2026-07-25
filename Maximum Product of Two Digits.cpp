class Solution {
    public:
        int maxProduct(int n) {
            int maxe = INT_MIN, secmaxe = INT_MIN;
            while(n != 0){
                int rem = n%10;
                if(rem > maxe) {
                    secmaxe = maxe;
                    maxe = rem;
                }
                else if(secmaxe < rem){
                    secmaxe = rem;
                }
                n /= 10;
            }
            return maxe * secmaxe;
        }
    };

/*--------------------------------- JAVA CODE -----------------------------------*/
class Solution {
    public int maxProduct(int n) {
        Integer maxe = Integer.MIN_VALUE, secmaxe = Integer.MIN_VALUE;
        while(n != 0){
            int rem = n%10;
            if(rem > maxe) {
                secmaxe = maxe;
                maxe = rem;
            }
            else if(secmaxe < rem){
                secmaxe = rem;
            }
            n /= 10;
        }
        return maxe * secmaxe;
    }
}