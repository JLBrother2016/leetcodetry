#include "../leetcodeutil.h"

class Solution {
// 找出数组中的无序部分, 无序子数组的起始和结束位置, 利用双指针来做
// 思考: 1. 用一个数组来存储一样电弧元素, 然后将元素进行排序, 首尾两端进行逐一比较, 直到内容不一样为止
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n-1], mx = nums[0];//最大值初始化为数组头, 最小值初始化为数组尾
        for(int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);       // 最大值
            mn = min(mn, nums[n-1-i]);   // 最小值
            if(mx > nums[i]) end = i;    // 最大值如果比数组头的数大, 就移动指针
            if(mn < nums[n-1-i])         // 最小值如果比数组尾的数小, 移动头指针
                start = n-1-i;
        }
        return end - start + 1;
    }
};

// // 方法一
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int res = 0, start = -1, n = nums.size();
//         for (int i = 1; i < n; ++i) {
//             if (nums[i] < nums[i - 1]) {
//                 int j = i;
//                 while (j > 0 && nums[j] < nums[j - 1]) {
//                     swap(nums[j], nums[j - 1]);
//                     --j;
//                 }
//                 if (start == -1 || start > j) start = j;
//                 res = max(res, i - start + 1);
//             }
//         }
//         return res;
//     }
// };
// // 方法二
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size(), i = 0, j = n - 1;
//         vector<int> t = nums;
//         sort(t.begin(), t.end());
//         while (i < n && nums[i] == t[i]) ++i;
//         while (j > i && nums[j] == t[j]) --j;
//         return j - i + 1;
//     }
// };
// // 方法三
// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n = nums.size(), start = -1, end = -2;
//         int mn = nums[n - 1], mx = nums[0];
//         for (int i = 1; i < n; ++i) {
//             mx = max(mx, nums[i]);
//             mn = min(mn, nums[n - 1 - i]);
//             if (mx > nums[i]) end = i;
//             if (mn < nums[n - 1 - i]) start = n - 1 - i;
//         }
//         return end - start + 1;
//     }
// };


int main(int argc, char const *argv[])
{
    vector<int> iv{2, 6, 4, 8, 10, 9, 15};
    cout << Solution().findUnsortedSubarray(iv) << endl;


    return 0;
}
