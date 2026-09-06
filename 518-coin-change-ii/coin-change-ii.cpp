class Solution {
public:
    int helper(int target,vector<int> &arr,int idx, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(idx == arr.size()-1) return (target % arr[idx] ==0);
         if(dp[idx][target]!=-1) return dp[idx][target];
        int notpickup= helper(target,arr,idx+1,dp);
        int pickup = 0;
        if(arr[idx]<=target)pickup= helper(target-arr[idx],arr,idx,dp);

         return dp[idx][target]= notpickup+pickup;

    }
    int change(int amount, vector<int>& coins) {
        int  n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(amount,coins,0,dp);
    }
};