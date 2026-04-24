class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int x = 0;      
        int count = 0; 
        
        for (char ch : moves) {
            if (ch == 'L') x++;
            else if (ch == 'R') x--;
            else count++;   
            }
        return max(abs(x + count), abs(x - count)); 
    }
};