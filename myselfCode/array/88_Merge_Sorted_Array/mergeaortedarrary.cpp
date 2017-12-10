#include "../leetcodeutil.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = n + m - 1;
        while(j >= 0) {
          nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];  //倒着来就不会有覆盖的问题
        }
    }
};

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         while( n > 0 )
//             nums1[ n + m - 1] = ( m == 0 || nums2[n - 1] > nums1[m - 1]) ? nums2[--n] : nums1[--m];
//     }
// };

int main(int argc, char const *argv[])
{
  

  return 0;
}
