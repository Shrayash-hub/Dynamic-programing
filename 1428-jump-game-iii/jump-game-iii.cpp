class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // applying bfs and checking at what positions we can go from a particular index
        queue<int> q;
        vector<int> vis(n,0);

        // from where we start
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int ind = q.front();
            q.pop();
            // if we reached to the index having value '0' then return true
            if(arr[ind] == 0) return true;

            // lets see the positions , we can go , from this index
            int first = ind + arr[ind];
            int second = ind - arr[ind];
            
            // boundary checks + if not visited -> to avoid cycles
            if (first < n && vis[first] != 1){
                q.push(first);
                vis[first] = 1;
            }
            if (second >= 0 && vis[second] != 1){
                q.push(second);
                vis[second] = 1;
            }
        }
        return false;
    }
};