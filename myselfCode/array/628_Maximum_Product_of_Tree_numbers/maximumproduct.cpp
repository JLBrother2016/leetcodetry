#include "../leetcodeutil.h"
/*class Solution {  //我理解错了，是相乘最大
public:
  int maximumProduct(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end()); 
    if(nums[len - 1] <= 0)
      return nums[len - 3] + nums[len - 2] + nums[len - 1];   
    else if (nums[0] >= 0){
      int muti = nums[len - 3] * nums[len - 2] * nums[len - 1];
      int sum = nums[len - 3] + nums[len - 2] + nums[len - 1];
      return max(muti, sum);
    }
    else if (nums[0] < 0 && nums[len-1] > 0){
      if(abs(nums[1]) > abs(nums[len - 2]))
        return nums[0] * nums[1] * nums[len -1];
      else return nums[0] * nums[len -2] * nums[len -1];
    }
    return nums[len - 3] + nums[len - 2] + nums[len - 1];  
  }
};*/
/*class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end()); 
    int temp1 = nums[len-1]*nums[len-2]*nums[len-3];
    int temp2 = nums[0]*nums[1]*nums[len-1];
    return max(temp2, temp1);
};
*/
// class Solution {
// public:
//   int maximumProduct(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int temp1 = nums[n-1]*nums[n-2]*nums[n-3];
//     int temp2 = nums[0]*nums[1]*nums[n-1];
//     return max(temp1, temp2);
//   }
// };

class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int min1 = 1001, min2 = 1001, max1 = -1001, max2 = -1001, max3 = -1001;
    for(int num : nums) {
      if(num <= min1) {
          min2 = min1;
          min1 = num;
      }
      else if(num <= min2) min2 = num;
      
      if(num >= max1) {
          max3 = max2;
          max2 = max1;
          max1 = num;
      }
      else if(num >= max2) {
          max3 = max2;
          max2 = num;
      }
      else if(num >= max3) max3 = num;
    }
    return max(max3 * max2 * max1, max1 * min1 * min2);
  }
};


int main(int argc, char const *argv[])
{
  vector<int> vect{1,2,3};
  vector<int> vect1{1,2,3,4};
  vector<int> vect2{1,0,100};

  cout << Solution().maximumProduct(vect2) << endl;
  return 0;
}




