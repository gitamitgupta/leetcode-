class Solution {
public:
    int helper(string &s1 , string &s2,int idx1,int idx2 ,vector<vector<int>> &dp){
    if(idx1<0 || idx2<0) return 0;
     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]= 1+helper(s1,s2,idx1-1,idx2-1,dp);
    return dp[idx1][idx2]= max(helper(s1,s2,idx1-1,idx2,dp),helper(s1,s2,idx1,idx2-1,dp));
   }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       return  helper(text1,text2,n-1,m-1,dp);
    }
};