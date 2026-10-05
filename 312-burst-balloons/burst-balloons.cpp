class Solution {
public:
     int helper(vector<int>& nums,int i,int j, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi =INT_MIN;
        for(int idx=i;idx<=j;idx++){
            int cost= nums[i-1]*nums[idx]*nums[j+1] + helper(nums,i,idx-1,dp)+helper(nums,idx+1,j,dp);
            maxi =max(maxi,cost);
        }
        return dp[i][j]= maxi;
     }
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(int i=0;i<nums.size();i++){
            arr.push_back(nums[i]);
        }
        arr.push_back(1);
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(arr,1,arr.size()-2,dp);
    }
};