class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<int> st;
        for(char ch : exp){
            if(ch== '(' || ch==',') continue;
            if(ch!=')') {
                st.push(ch);
                 continue;
            }
            else {
                bool istrue= false;
                bool isfalse = false;
                while(st.top()=='t'||st.top()=='f'){
                    if(st.top()=='t') istrue = true;
                    else isfalse=true;

                    st.pop();
                }
                char oper =st.top();
                st.pop();
                if(oper=='!'){
                    if(istrue) st.push('f');
                    else st.push('t');
                }
                if(oper=='&'){
                    if(isfalse) st.push('f');
                    else st.push('t');
                }
                if(oper=='|'){
                    if(istrue) st.push('t');
                    else st.push('f');
                }



              
            }
        }
        return st.top() == 't';
    }
};