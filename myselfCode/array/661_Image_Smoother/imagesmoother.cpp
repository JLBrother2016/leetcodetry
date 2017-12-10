#include "../leetcodeutil.h"
/*class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
      int m = M.size(), n = M[0].size();
      if (m == 0 || n == 0) return {{}};
      vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
      for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              int sum = M[i][j], cnt = 1;
              for (int k = 0; k < dirs.size(); k++) {
                  int x = i + dirs[k][0], y = j + dirs[k][1];
                  if (x < 0 || x > m - 1 || y < 0 || y > n - 1) continue;
                  sum += (M[x][y] & 0xFF);
                  cnt++;
              }
              M[i][j] |= ((sum / cnt) << 8);
          }
      }
       for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
              M[i][j] >>= 8;
          }
       }
      return M;
  }
};*/

/*class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n_rows = M.size();
        int n_cols = M[0].size();
        std::vector<std::vector<int> > M_C;
        std::vector<std::pair<int,int> > eightConnected  = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int r=0;r<n_rows;r++){
            std::vector<int> v;
            for(int c=0;c<n_cols;c++){
                int sum = M[r][c];
                int validCells = 1;
                for(auto i:eightConnected){
                    int nr = r + i.first;
                    int nc = c + i.second;
                    if(nr>=0 && nr<n_rows && nc>=0 && nc<n_cols){
                        validCells++;
                        sum += M[nr][nc];
                    }
                }
                int val = sum/validCells;
                v.push_back(val);
            }
            M_C.push_back(v);
        }
        return M_C;
    }

};*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        
        vector<vector<int>> res(M.size(), vector<int>(M[0].size(),0));
        vector<pair<int,int>> surr = {  {-1,-1}, {-1, 0}, {-1, 1},
                                        {0, -1},  {0,0}, {0, 1},
                                        {1, -1},  {1,0}, { 1,1}};
        int m = M.size();
        int n = M[0].size();
        
        for(int i=0; i < m; i++) {
            for( int j=0; j < n; j++) {
                
                int tot = 0;
                int val = 0;
                for(auto it: surr) {
                    int r = i + it.first;
                    int c = j + it.second;
                    
                    if ( (r >= 0) && ( r < m) && (c >=0) && (c < n) ) {
                        tot++;
                        val = val + M[r][c];
                    }
                }
                if( tot)
                    res[i][j] = (val/tot);
            }
        }
        
        return res;
        
    }
};

int main(int argc, char const *argv[])
{
  vector<vector<int>> vect{{1,1,1},
                           {1,0,1},
                           {1,1,1} };

  cout << Solution().imageSmoother(vect) << endl;

  return 0;
}
