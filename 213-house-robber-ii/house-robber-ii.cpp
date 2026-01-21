class Solution {
public:
    int rob(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        
        
        vector<int> previous(arr.size());
        previous[0] = arr[0];
        previous[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<arr.size()-1;i++){
            previous[i] = max(previous[i-1], arr[i]+previous[i-2]);
        }
        vector<int> previous2(arr.size());
        previous2[0] = 0;
        previous2[1] = arr[1];

        for(int i=2;i<arr.size();i++){
            previous2[i] = max(previous2[i-1], arr[i]+previous2[i-2]);
        }
        return max(previous2[arr.size()-1],previous[arr.size()-2]);
    }
};