class Solution {
public:
    string removeStars(string arr) {
        int i = 0;

        for (int j = 0; j < arr.length(); j++) {
            if (arr[j] == '*') {
                i--; 
            } else {
                arr[i++] = arr[j]; 
            }
        }

        return arr.substr(0,i);
    }
};