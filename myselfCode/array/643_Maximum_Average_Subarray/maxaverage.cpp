#include "../leetcodeutil.h"

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) { //暴力搜索超时了
//         int len = nums.size();
//         int sum = 0;
//         int temp = -100001;
//         for (int i = 0; i < len - k + 1; i++){
//           sum = 0;
//           for(int j = i; j < k + i; ++j){
//             sum += nums[j];
//             // cout << nums[j] << endl;
//           }
//           // cout << "sum:" << sum << endl;
//           temp = max(temp, sum);
//         }
//         return (double)temp / k;  
//     }
// };

/*class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      double sum = 0, res = INT_MIN;
      for(int i = 0; i < nums.size(); i++) {
          if(i < k) sum += nums[i];
          else {
              res = max(sum, res);
              sum += nums[i] - nums[i-k];
          }
      }
      res = max(sum, res);
      return res/k;
    }
};*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int Sum = 0;
        int MaxAverageSum = 0;
        for(int i = 0; i < nums.size(); i++){
            Sum += nums[i];
            if(i == k-1)
              MaxAverageSum = Sum;
            else if(i >= k){
                Sum -= nums[i-k];
                MaxAverageSum = max(MaxAverageSum, Sum);
            }
        }
        return MaxAverageSum*1.0 / k;
        
        
    }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{1,12,-5,-6,50,3};
  vector<int> vect1{-1};
  vector<int> vect2{8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,
    -2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,
    -9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,
    3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};

  cout << Solution().findMaxAverage(vect2, 93) << endl;

  return 0;
}

