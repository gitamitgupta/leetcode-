class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> str(s.size());
        for(int i =0;i<indices.size();i++){
            str[indices[i]]=s[i];
        }
          string ans="";
         for(int i=0;i<str.size();i++){
               ans+=str[i];
         }
          return ans;
    }
};