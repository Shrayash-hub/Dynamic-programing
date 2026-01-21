class Solution {
public:
    int climbStairs(int n) {
        // using dp
        if(n==0) return 1;
        if(n==1) return 1;

        vector<int> previous(n+1);
        previous[0] = 1;
        previous[1] = 1;

        for(int i=2;i<=n;i++){
            previous[i] = previous[i-2] + previous[i-1];
        }
        return previous[n];
    }
};