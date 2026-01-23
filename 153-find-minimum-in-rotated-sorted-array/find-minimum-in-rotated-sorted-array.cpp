class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        if(arr[low]<arr[high]){ // means array is already sorted 
                return arr[low];
            }
        while(low<high){
            int mid = low+(high-low)/2;
            if(arr[mid]>arr[arr.size()-1]){   // if arr[mid]<=arr[high] , then it means right half is sorted and we will never get mimimum on right side , because values are increasing at that side
                low = mid+1;
                  // reduce search space to the left side
            }
            else{
                high = mid;// and if right part is not sorted than mid can be a break point so min value can be on right half
            }
        }
        return arr[low];
    }
};