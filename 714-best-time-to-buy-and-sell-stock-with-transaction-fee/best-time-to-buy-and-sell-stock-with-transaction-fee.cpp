class Solution {
public:
    int helper(vector<int>& arr,int idx, int buy,vector<vector<int>>& dp ,int fee ){
        if(idx==arr.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
         int profit;
        if(buy){
        profit= max(-arr[idx]+ helper(arr,idx+1,0,dp,fee),0+helper(arr,idx+1,1,dp,fee));
        }
        else {// just sub fee after the sell  fee will cut
              profit= max(arr[idx]-fee+helper(arr,idx,1,dp,fee), 0+helper(arr,idx+1,0,dp,fee));
        }

        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));

        return helper(prices,0,1,dp,fee);
    }
};