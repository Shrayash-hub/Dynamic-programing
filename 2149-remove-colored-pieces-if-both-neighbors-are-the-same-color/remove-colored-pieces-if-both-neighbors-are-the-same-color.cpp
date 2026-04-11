class Solution {
public:
    bool winnerOfGame(string colors) {
        int consA = 0, consB = 0;
        int chanceA = 0, chanceB = 0;

        for(auto ch : colors){
            if(ch == 'A'){
                consB = 0;
                consA++;
                if(consA >= 3) chanceA++;
            }else{
                consA = 0;
                consB++;
                if(consB >= 3) chanceB++;
            }
        }

        return chanceA > chanceB;
    }
};