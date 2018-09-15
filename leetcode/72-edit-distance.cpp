#include "../leetcodeutil.h"

// class Solution {
// //一道很经典的动态规划题目，记忆化递归
// // d[i][j]表示字符串1,word1[0,...,i]经过d[i][j]步操作转换为字符串2，word2[0,...,j]
// public:
//     int minDistance(string word1, string word2) {
//         int l1 = word1.length();
//         int l2 = word2.length();
//         // 数组需要多申请一行和一列空间缓存边界条件
//         d_ = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));

//         return minDistance(word1, word2, l1, l2);
//     }
// private:
// 	vector<vector<int>> d_;
// 	int minDistance(string& word1, string& word2, int l1, int l2) {
// 		if(l1 == 0) return l2;
// 		if(l2 == 0) return l1;
// 		if(d_[l1][l2] >= 0) return d_[l1][l2]; //记忆化递归
// 		int ans = -1;
// 		if(word1[l1-1] == word2[l2-1]) {  //两字符串最后位置的元素相同
// 			return minDistance(word1, word2, l1-1, l2-1);
// 		}
// 		// 否则是general case
// 		ans = min(minDistance(word1, word2, l1-1, l2),  //字符串1删除一个元素
// 			  min(minDistance(word1, word2, l1, l2-1),  //字符串2增加一个元素
// 				  minDistance(word1, word2, l1-1, l2-1))) + 1; //互相交换

// 		return d_[l1][l2] = ans;  
// 	}
// };

class Solution {
//一道很经典的动态规划题目，递推求解
// d[i][j]表示字符串1,word1[0,...,i]经过d[i][j]步操作转换为字符串2，word2[0,...,j]
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        // 数组需要多申请一行和一列空间缓存边界条件
        vector<vector<int>> d_(l1+1, vector<int>(l2+1, INT_MAX));
        for(int i = 0; i <= l1; ++i) {
        	d_[i][0] = i;
        }  //处理边界条件
        for(int j = 1; j <= l2; ++j) {
        	d_[0][j] = j;
        }
        for(int i = 1; i <= l1; ++i) {
        	for(int j = 1; j <= l2; ++j) {
        		int c = (word1[i-1] == word2[j-1]) ? 0 : 1; //如果相等就直接跳过
        		d_[i][j] = min(d_[i-1][j-1] + c,	 //如果不相等就进行一次操作
        			       min(d_[i][j-1], d_[i-1][j]) + 1);//进行一次插入或删除操作
        	}
        }

        return d_[l1][l2];
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().minDistance("horse", "ros") << endl;

	return 0;
}
