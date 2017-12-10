#include "../leetcodeutil.h"

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//       int len = nums.size();
//       int result = 0;
//       int temp = 0;
//       sort(nums.begin(), nums.end());
//       for(int i = 0; i < len; ++i) {
//         if(nums[i] == val){
//           result++;
//           temp = i;
//           // cout << "result:" << result << endl;
//         }
//       }
//       // cout << temp << endl;
//       // cout << result << endl;
//       nums.erase (nums.begin() + temp - result + 1, nums.begin() + temp + 1);

//       return result;
//     }
// };
class Solution {
public:  
  int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for(int i = 0 ; i < nums.size() ; ++i) {
        if(nums[i] == val)
            cnt++;
        else
            nums[i-cnt] = nums[i];
    }
    return nums.size()-cnt;
  }
};

/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
         // auto v = std::remove(nums.begin(), nums.end(), val);
         // int sz = distance(nums.begin(), v);
         // nums.resize(sz);
         // return sz;
        
        
    
        int sz = nums.size();
        if( sz == 0 ) return 0;
        while( nums[sz-1] == val && sz >0 ) sz--;
        for( int i=0; i<sz; ++i){
            if( nums[i] == val ) {
                nums[i] = nums[sz-1];
                sz--;
                while( nums[sz-1] == val ) sz--;
            }
        }
        nums.resize(sz);
        return sz;
    
    }
};
*/


int main(int argc, char const *argv[])
{
  vector<int> vect{3,2,2,3};
  vector<int> vect1{1};
  vector<int> vect2{2,4,1};

  cout << Solution().removeElement(vect1, 1) << endl;

  cout << vect1 << endl;

  return 0;
}
