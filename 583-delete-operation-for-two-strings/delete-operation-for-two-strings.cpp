class Solution {
public:
int helper(string &s1 , string &s2,int idx1,int idx2 ,vector<vector<int>> &dp){
    if(idx1<0 || idx2<0) return 0;
     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(s1[idx1]==s2[idx2]) return dp[idx1][idx2]= 1+helper(s1,s2,idx1-1,idx2-1,dp);
    return dp[idx1][idx2]= max(helper(s1,s2,idx1-1,idx2,dp),helper(s1,s2,idx1,idx2-1,dp));
   }
    int minDistance(string word1, string word2) {
        int n= word1.size();
        int m= word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int k = helper(word1,word2,n-1,m-1,dp);
        
        int deletfrom1= n-k;
        int deletfrom2 =m-k;

        return deletfrom1+deletfrom2;


    }
};