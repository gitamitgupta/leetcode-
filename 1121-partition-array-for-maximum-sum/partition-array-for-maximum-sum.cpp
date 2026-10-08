class Solution {
public:
    int helper(vector<int> &arr,int i,int k,vector<int>&dp ){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int maxsum=INT_MIN;
        for(int j=i;j<min(i+k,(int )arr.size());j++){
          len++;
          maxi=max(maxi,arr[j]);
          int sum = len *maxi + helper(arr,j+1,k,dp);
          maxsum=max(maxsum,sum);
        }
     return dp[i]=maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helper(arr,0,k,dp);

    }
};