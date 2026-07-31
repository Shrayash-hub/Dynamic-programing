class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum = 0;
        int maxi = 0;
        int rSum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }
        maxi = lSum;
        int rightIndex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lSum = lSum - cardPoints[i];
            rSum += cardPoints[rightIndex];
            maxi = max(maxi, lSum + rSum);
            rightIndex--;
        }
        return maxi;
    }
};