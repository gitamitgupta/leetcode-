class Solution {
public:
int helper(vector<int> &arr , int idx,int buy ,int cap,vector<vector<vector<int>>>&dp ){
    if(cap==0) return 0;
    if(idx==arr.size()) return 0;
    if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
    int profit;
    if(buy){
        profit= max(-arr[idx]+helper(arr,idx+1,0,cap,dp),0+helper(arr,idx+1,1,cap,dp));
    }else{
        profit= max( arr[idx]+helper(arr,idx+1,1,cap-1,dp),0+helper(arr,idx+1,0,cap,dp));
    }

    return dp[idx][buy][cap]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
         int n =prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int> (k+1,-1)));
        return helper(prices,0,1,k,dp);
    }
};