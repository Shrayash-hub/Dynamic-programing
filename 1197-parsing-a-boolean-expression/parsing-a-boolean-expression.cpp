class Solution {
public:
    // "!(&(f,t))"
    // 012 
    // "f"
    // "&(t,f,!(f),t)"
    bool helper(string& expression, int& idx){
        //bc
        if(expression[idx]=='f'){
            idx++;
            return false;
        }
        else if(expression[idx]=='!'){
            idx+=2;
            //rr
            bool res= helper(expression,idx);
            //task
            idx++;
            return !res;
        }
        else if(expression[idx]=='&'){
            bool res=true;
            idx+=2;
            while(expression[idx]!=')'){
                if(expression[idx]==','){
                    idx++;
                }
                else{
                   bool temp=helper(expression,idx); 
                   res= res& temp;
                }
            }
            idx++;
            return res;
        }
        // 0 | 1 | 0=1
        else if(expression[idx]=='|'){
            bool res=false;
            idx+=2;
            while(expression[idx]!=')'){
                if(expression[idx]==','){
                    idx++;
                }
                else{
                   bool temp=helper(expression,idx); 
                   res= res| temp;
                }
            }
            idx++;
            return res;
        }
        idx++;
        return true;
    }
    bool parseBoolExpr(string expression) {
        int idx=0;
        return helper(expression, idx);
    }
};