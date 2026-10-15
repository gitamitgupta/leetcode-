class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
      int minrow=0;
      int mincol=0;
      int maxrow= matrix.size()-1;
      int maxcol= matrix[0].size()-1;
      int maxcount= matrix.size()*matrix[0].size();
      int count=0;
      while(minrow<=maxrow && mincol<=maxcol){
          for(int i=mincol;i<=maxcol && count<maxcount;i++){
                 ans.push_back(matrix[minrow][i]);
                
                 count++;
          }
           minrow++;
          for(int j=minrow;j<=maxrow && count<maxcount;j++){
            ans.push_back(matrix[j][maxcol]);
            
            count++;
          }
          maxcol--;
          for(int k=maxcol;k>=mincol&& count<maxcount;k--){
            ans.push_back(matrix[maxrow][k]);
           
            count++;
          }
           maxrow--;
          for(int m=maxrow ;m>=minrow&& count<maxcount;m--){ ans.push_back(matrix[m][mincol]);
         
          count++;

          }
           mincol++;
      }


      return ans;
    }
};