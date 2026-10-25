class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans;
        int n= nums.size();
        int mindiff = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<n-2 ;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
             int sum= nums[i]+nums[j]+nums[k];
             if(sum==target){
                return target;
             }
             else if(sum> target){
                k--;
             }
             else{
                j++;
             }
              int diff = abs(sum-target);
              if(diff< mindiff){
                mindiff= diff;
                ans=sum;
              }
            }
        }
        return ans;
    }
};