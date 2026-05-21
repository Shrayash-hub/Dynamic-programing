class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> prefix(customers.size() + 1, 0);
        int i = 1;
        for (auto it : customers) {
            if (it == 'N') {
                prefix[i] = prefix[i - 1] + 1;
            } else {
                prefix[i] = prefix[i - 1];
            }
            i++;
        }
        vector<int> suffix(customers.size() + 1, 0);
        for (int i = customers.size() - 1; i >= 0; i--) {
            if (customers[i] == 'Y') {
                suffix[i] = suffix[i + 1] + 1;
            } else {
                suffix[i] = suffix[i + 1];
            }
        }

        int index = -1;
        int mini = INT_MAX;
        for (int j = 0; j <= customers.size(); j++) {
            if (prefix[j] + suffix[j] < mini) {
                mini = prefix[j] + suffix[j];
                index = j;
            }
        }
        return index;
    }
};