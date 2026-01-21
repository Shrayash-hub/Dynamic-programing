class Solution {
public:
    int rob(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        if(arr.size()==2) return max(arr[0],arr[1]);
        
        vector<int> previous(arr.size());
        previous[0] = arr[0];
        previous[1] = max(arr[0],arr[1]);
        
        for(int i=2;i<arr.size();i++){
            previous[i] = max(previous[i-1], arr[i]+previous[i-2]);
        }
        return previous[arr.size()-1];
    }
};