#include "../leetcodeutil.h"

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 
};

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 0)   return true;
    
        int cnt = 0;
        for(vector<int>::size_type index = 1; index < nums.size(); index++){
            if(nums[index] < nums[index-1]){
                cnt+=1;
                if(index < 2 || nums[index] >= nums[index-2])  nums[index-1] = nums[index]; 
                else nums[index] = nums[index-1];  
            }
        }
        return cnt <= 1;
    }
};

int main(int argc, char const *argv[])
{
  
  vector<int> vect1{4,2,1};
  cout << Solution().checkPossibility(vect1) << endl;

  return 0;
}
