class Solution {
public:
    int helper(vector<int>& nums, int target,int d1,int tsum,int idx){
        if(idx==nums.size()){
            if(2*d1-tsum==target) return 1;
            else return 0;


        }

        int pickup = helper(nums,target,d1+nums[idx],tsum,idx+1);
        int notpickup=helper(nums,target,d1,tsum,idx+1);

        return pickup +notpickup;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(auto el : nums) sum+=el;
        return helper( nums,target,0,sum,0);
    }
};