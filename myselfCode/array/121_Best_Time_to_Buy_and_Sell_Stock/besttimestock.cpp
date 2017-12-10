#include "../leetcodeutil.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 1)
            return 0;
        int maxm = 0;
        int minm = INT_MAX;
        for(int i = 0; i < len; ++i){
            minm = min(minm, prices[i]);
            maxm = max(maxm, prices[i] - minm);
        }
        return maxm;
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{7, 1, 5, 3, 6, 4};
  vector<int> vect1{7, 6, 4, 3, 1};
  vector<int> vect2{2,4,1};

  cout << Solution().maxProfit(vect2) << endl;

  return 0;
}
