class Solution {
public:
    bool comper(string &s1,string &s2 ){
        if(s1.size()!= s2.size()+1) return false;
        int f=0;
        int s=0;
        while(f < s1.size() && s < s2.size()){
            if(s1[f]==s2[s]){
                f++;
                s++;
            }
            else {
                f++;
            }
        }
      return s == s2.size();
        
    }
  static  bool com(const string &s1, const string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),com);
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=1 ;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(comper(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]= dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};