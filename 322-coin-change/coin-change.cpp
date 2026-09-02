class Solution {
public:
int helper(vector<int>& arr,int idx,int target,vector<vector<int>> &dp){
    
    if(target==0) return 0;
    if(idx==0){
         if(target % arr[0] == 0)
                return target / arr[0];
        else return 1e7;

    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int notpickup = 0+ helper(arr,idx-1,target,dp);
    int pickup = 1e7;
    if(target>= arr[idx]) pickup = 1+ helper(arr,idx,target-arr[idx],dp);

    return dp[idx][target]= min(notpickup,pickup);

}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
       int ans=helper(coins,n-1,amount,dp);

       if(ans>=1e7) return -1;
       return ans;
    }
};