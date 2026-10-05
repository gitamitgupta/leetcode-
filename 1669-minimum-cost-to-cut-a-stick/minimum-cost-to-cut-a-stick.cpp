class Solution {
public:
    int helper(int n, vector<int>& cuts,int i,int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i;k<=j;k++){
           int cost =cuts[j+1]-cuts[i-1]+helper(n,cuts,i,k-1,dp)+helper(n,cuts,k+1,j,dp);
           mini = min(mini,cost);
        }
        return dp[i][j]= mini;

    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> arr;
        arr.push_back(0);
        for(int i=0;i<cuts.size();i++){
            arr.push_back(cuts[i]);
        }
        arr.push_back(n);
        int m=arr.size();
       vector<vector<int>> dp(m,vector<int>(m,-1));
        return helper(n,arr,1,arr.size()-2,dp);


    }
};