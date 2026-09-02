class Solution {
public:
    int helper(vector<int>& nums, int target,int d1,int tsum,int idx,vector<vector<int>>&dp){
        if(idx==nums.size()){
            if(2*d1-tsum==target) return 1;
            else return 0;


        }
        if(dp[idx][d1]!= -1)  return dp[idx][d1];
        int pickup = helper(nums,target,d1+nums[idx],tsum,idx+1,dp);
        int notpickup=helper(nums,target,d1,tsum,idx+1,dp);

        return dp[idx][d1]= pickup +notpickup;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(auto el : nums) sum+=el;
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        return helper( nums,target,0,sum,0,dp);
    }
};