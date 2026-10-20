class Solution {
public:
     int count(int num){
        int cnt=0;
        while(num>0){
            cnt++;
            num=num/10;

        }
        return cnt;
     }
    int findNumbers(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size();i++ ){
            if(count(nums[i])%2==0)c++;
        }

        return c;
    }
};