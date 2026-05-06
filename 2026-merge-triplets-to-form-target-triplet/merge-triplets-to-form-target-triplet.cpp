class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int>
            s; // Initialize a set to store indices of matching elements

        // Iterate through each triplet
        for (int i = 0; i < triplets.size(); i++) {
            // If any element of the triplet is greater than the corresponding
            // element of the target triplet, skip
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]) {
                continue;
            }

            // Check if any element of the triplet matches the corresponding
            // element of the target triplet
            for (int j = 0; j < 3; j++) {
                if (triplets[i][j] == target[j]) {
                    s.insert(
                        j); // Add the index of the matching element to the set
                }
            }
        }

        // Check if all three indices are present in the set
        return s.size() == 3;
    }
};