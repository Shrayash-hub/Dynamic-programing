class Solution {
public:
    int fib(int n) {
        // using dp
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> previous(n+1);
        previous[0] = 0;
        previous[1] = 1;

        for(int i = 2; i <= n; i++) {
            previous[i] = previous[i-1] + previous[i-2];
        }
        return previous[n];
    }
};