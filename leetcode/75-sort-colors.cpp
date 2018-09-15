#include "../leetcodeutil.h"

// class Solution {  //思路错了, 应该用双指针来求解
// //利用快排的思想来求解这道题, 把小于1的数放前面，大于1的放后面
// // 应该要递归来求解
// public: 
//     void sortColors(vector<int>& nums) {
//         if(nums.size() == 0)
//         	return;

//     }
// private:
// 	void sortColors(vector<int>& nums, int l, int r) {
// 		if(l > r) return;

// 	}
// };

class Solution {
// 应该使用双指针进行求解
public: 
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0)
        	return;
        int first, last;
        int index;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
        	if(nums[i] != 0) {
        		first = i;
        		break;
        	}
        }
        for(int i = len - 1; i >= 0; --i) {
        	if(nums[i] != 2) {
        		last = i;
        		break;
        	}
        }
        // cout << first << endl;
        // cout << last << endl;
        index = first;
        while(index <= last) {
        	if(nums[index] == 1) ++index;
        	else if(nums[index] == 0) {
        		swap(nums[index], nums[first]);
        		++index;
        		++first;
        	} else if(nums[index] == 2) {
        		swap(nums[index], nums[last]);
        		--last;
        		// cout << last << "  " << nums << endl;
        	}
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // swap low and mid if encounters 0
        // swap high and mid if encounters 2
        int low = 0, high = nums.size()-1, mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums, low, mid);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums, high, mid);
                high--;
            }
        }
        
    }
    
private:
    void swap(vector<int>& nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> iv{2,0,2,1,1,0,2};
	Solution().sortColors(iv);
	cout << iv << endl;

	return 0;
}
