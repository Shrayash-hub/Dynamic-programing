class Solution {
public:
    int tribonacci(int n) {
        int prev2 = 0;
        int prev1 = 1;
        int prev = 1;
        if (n == 0)
            return 0;
        if (n == 1)
            return prev1;
        if (n == 2)
            return prev1;
        if (n == 3)
            return prev + prev1;
        int curr;
        for (int i = 3; i <= n; i++) {
            curr = prev + prev1 + prev2;
            prev2 = prev1;
            prev1 = prev;
            prev = curr;
        }
        return curr;
    }
};