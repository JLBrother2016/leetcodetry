#include "../leetcodeutil.h"

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int len = prices.size(); 
      int vMax = 0, vMin = 0;
      for(int i = 0; i < len; ++i){
        vMax = max(vMax, prices[i]);
        vMin = min(vMin, prices[i]);
      }

      return vMax - vMin;
    }
};*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//       int len = prices.size(); 
//       int result = 0;
//       for(int i = 0; i < len - 1; ++i){
//         if(prices[i+1] > prices[i])
//           result += prices[i+1] - prices[i];
//       }

//       return result;
//     }
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int retVal=0;
        for(int i=1; i<prices.size(); i++){
            retVal+=max(0, prices[i]-prices[i-1]);
        }
        return retVal;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{0, 1, 0, 3, 12}; 
  vector<int> vect1{4,2,4,0,0,3,0,5,1,0};

  Solution().moveZeroes(vect1);

  return 0;
}


