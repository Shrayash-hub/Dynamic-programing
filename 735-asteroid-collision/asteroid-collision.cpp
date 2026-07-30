class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> arr;
        for (auto it : asteroids) {
            if (it >= 0)
                st.push(it);
            else {
                while (st.size() > 0 && st.top() > 0 && abs(it) > st.top()) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0)
                    st.push(it);
                else if (st.top() + it == 0)
                    st.pop();
            }
        }
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            arr.push_back(curr);
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};