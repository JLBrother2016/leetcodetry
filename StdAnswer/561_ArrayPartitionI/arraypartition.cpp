// #include <iostream>
#include "leetcodeutil.h"

// using namespace std;

class Solution {   
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> hashtable(20001,0);
        for(size_t i=0;i<nums.size();i++)  //bucket sort
        {
            hashtable[nums[i]+10000]++;
        }
        int ret=0;
        int flag=0;
        for(size_t i=0;i<20001;){
            if((hashtable[i]>0)&&(flag==0)){
                ret=ret+i-10000;
                flag=1;
                hashtable[i]--;
            }else if((hashtable[i]>0)&&(flag==1)){
                hashtable[i]--;
                flag=0;
            }else i++;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
  int start = TimeUtil::getCurrentTimeMs();

  std::vector<int> vct{1, 4, 2, 3};
  for(int i = 0; i < 100000; i++)
    Solution().arrayPairSum(vct);
  cout << Solution().arrayPairSum(vct) << endl;

  int end = TimeUtil::getCurrentTimeMs();

  cout << (end - start) << endl;

  return 0;
}

