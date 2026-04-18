class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int x = n;
        int i = 0;
        while(x>0){
            int digit = x%10;
            rev = rev*10 + digit;
            x = x/10;
        }
        return abs(n-rev);
        
    }
};