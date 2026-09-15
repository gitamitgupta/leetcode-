class Solution {
public:
    int reverse(int x) {
        if( x> INT_MAX || x< INT_MIN) return 0;
        long long ans=0;
        if(x<0){
          long long y = -(long long)x;
          while(y>0){
                ans*=10;
                if (ans > INT_MAX || ans < INT_MIN)
                return 0;
                int rem = y%10;
                ans=ans+rem;
                y=y/10;

            }
            ans= - ans;
        }
        else{
           
            while(x>0){
                ans*=10;
                if (ans > INT_MAX || ans < INT_MIN)
                return 0;
                int rem = x%10;
                ans=ans+rem;
                x=x/10;

            }
        }
      return (int)ans;
    }
};