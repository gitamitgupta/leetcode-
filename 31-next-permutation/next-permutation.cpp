class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n=nums.size();
      int pvoit=-1;
      for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){ pvoit=i;
        break;}
      }
      if(pvoit==-1) {
        reverse(nums.begin(),nums.end());
        return;
        
      }
      reverse(nums.begin()+pvoit+1,nums.end());
      int swapind;
      for(int i=pvoit+1;i<n;i++){
        if(nums[i]>nums[pvoit]){
            swapind=i;
            break;
        }
      }
      swap(nums[pvoit],nums[swapind]);
      
      
      }
};