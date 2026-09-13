class Solution {
public:
    int helper(vector<int>& arr,int idx, int buy,vector<vector<int>>& dp ){
        if(idx>arr.size()) return 0;
        if(idx==arr.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
         int profit;
        if(buy){
        profit= max(-arr[idx]+ helper(arr,idx+1,0,dp),0+helper(arr,idx+1,1,dp));
        }
        else {
              profit= max(arr[idx]+helper(arr,idx+2,1,dp), 0+helper(arr,idx+1,0,dp));
        }

        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return helper(prices,0,1,dp);
    }
};