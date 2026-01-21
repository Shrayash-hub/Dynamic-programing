class Solution {
public:
    int tribonacci(int n) {
        // using dp
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        vector<int> previous(n+1);

        previous[0] = 0;
        previous[1] = 1;
        previous[2] = 1;
        for(int i=3;i<=n;i++){
            previous[i] = previous[i-3] + previous[i-2] + previous[i-1];
        } 
        return previous[n];
    }
};