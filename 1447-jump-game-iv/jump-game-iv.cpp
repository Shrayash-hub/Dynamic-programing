class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        // if we are already at last index -> directly return zero
        if(n == 1) return 0;

        // map value -> all the indexes having that value(i)
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        // applying bfs from index zero to explore all the nei
        queue<int> q;
        q.push(0);

        // visited array is required to avoid revisiting to the same index
        vector<bool> vis(n, false);
        vis[0] = true;

        int jumps = 0;

        while(!q.empty()){
            int size = q.size();

            // process one bfs level all the nodes that reachable in same number of jumps
            while(size--){
                int idx = q.front();
                q.pop();

                // if we reached at last index -> return number of jumps
                if(idx == n - 1) return jumps;

                // jump to i+1 index
                if(idx + 1 < n && !vis[idx + 1]){
                    vis[idx + 1] = true;
                    q.push(idx + 1);
                }

                // jump to i-1 index
                if(idx - 1 >= 0 && !vis[idx - 1]){
                    vis[idx - 1] = true;
                    q.push(idx - 1);
                }

                // jump to all indices having the same value
                for(int next : mp[arr[idx]]){
                    if(!vis[next]){
                        vis[next] = true;
                        q.push(next);
                    }
                }
                // clear the list so we never process this value again in future
                mp[arr[idx]].clear();
            }
            // moving to next level
            jumps++;
        }
        return -1;
    }
};