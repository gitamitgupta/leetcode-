class Solution {
public:
     int helper(int i,int j1,int j2,int r,vector<vector<int>>& arr,vector<vector<vector<int>>> &dp){
        if(j1<0 ||j1>=arr[0].size() || j2<0 || j2>=arr[0].size()) return -1e8;
        if(i==r-1){
            if(j1==j2) return arr[i][j2];
            else return arr[i][j1]+arr[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=0;
        for(int d1=-1 ;d1<=1;d1++){
            for (int d2=-1;d2<=1 ;d2++ ){
               if(j1!=j2){
                int temp = arr[i][j1]+arr[i][j2]+ helper(i+1,j1+d1,j2+d2,r,arr,dp);
                maxi=max(maxi,temp);
               }
               else{
                int temp =arr[i][j2]+ helper(i+1,j1+d1,j2+d2,r,arr,dp);
                maxi=max(maxi,temp);

               }
            }
        }


        return dp[i][j1][j2]=maxi;
     }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        int k= grid[0].size();
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return helper(0,0,k-1,n,grid,dp);
    }
};