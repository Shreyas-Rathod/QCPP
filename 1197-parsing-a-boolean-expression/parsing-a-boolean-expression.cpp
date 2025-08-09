class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char>st;
        bool hasfalse = false, hastrue = false;
        char op;
        
        for(char x : exp){
            if(x == ',' || x == '(') continue;
            if(x == 't' || x == 'f' || x == '!' || x == '&' || x == '|') st.push(x);
            else if(x == ')'){
                hasfalse = false;
                hastrue = false;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|'){
                    if(st.top() == 't') hastrue = true;
                    else if(st.top() == 'f') hasfalse = true;
                    st.pop();
                }
                op = st.top();
                st.pop();
                if(op == '!') st.push(!hastrue ? 't' : 'f');
                else if(op == '&') st.push(hasfalse ? 'f' : 't');
                else if(op == '|') st.push(hastrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};