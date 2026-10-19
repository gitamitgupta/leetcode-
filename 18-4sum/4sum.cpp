class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0 ;i<n-3;i++){
            if(i>0 &&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1] ) continue;
                int k=j+1;
                int m= n-1;
                while(k<m){
                    long long sum = 1LL * nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[m]});
                        k++;
                        m--;
                        while(k<m && nums[k-1]==nums[k]) k++;
                        while(k<m && nums[m] == nums[m+1]) m--;
                    }
                    else if(sum > target )m--;
                    else k++;
                }
            }
        }
          return ans;
    }
};