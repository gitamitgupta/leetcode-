class Solution {
public:
    string interpret(string command) {
        string ans="";
        int n=command.size();
        for(int i=0;i<n;i++){
            if(i!=n-1&&command[i]=='(' &&command[i+1]==')') ans+="o";
            else if(i!=n-1 && command[i]=='(' &&command[i+1]!=')') continue;
            else if(command[i]==')') continue;
            else {
                ans+= command[i];
            }
        }

        return ans;
    }
};