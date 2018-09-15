#include "../leetcodeutil.h"

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int len = strs.size();
//         vector<vector<string>> ans;
//         if(len == 0) 
//         	return ans;
//         unordered_map<string, vector<string>> hash_table;
//         for(string& str : strs) {
//         	string tmp = str;
//         	sort(tmp.begin(), tmp.end());
//         	if(hash_table.count(tmp) == 0) {
//         		vector<string> item;
//         		item.push_back(str);
//         		hash_table[tmp] = item;
//         	} else {
//         		hash_table[tmp].push_back(str);
//         	}
//         }
//         for(auto &it : hash_table) {
//             ans.push_back(it.second);
//         }
//         // cout << ans << endl;

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int len = strs.size();
//         vector<vector<string>> ans;
//         if(len == 0) 
//             return ans;
//         unordered_map<string, vector<string>> hash_table;
//         for(string& str : strs) {
//             vector<int> count(26, 0);
//             for(auto & ch : str) {
//                 ++count[ch - 'a'];
//             }
//             string tmp = "";
//             for(auto &ch : str) {
//                 tmp += count[ch - 'a'];
//                 tmp += ch;
//             }
//             sort(tmp.begin(), tmp.end());
//             if(hash_table.count(tmp) == 0) {
//                 vector<string> item;
//                 item.push_back(str);
//                 hash_table[tmp] = item;
//             } else {
//                 hash_table[tmp].push_back(str);
//             }
//         }
//         for(auto &it : hash_table) {
//             ans.push_back(it.second);
//         }
//         // cout << ans << endl;

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 利用质数做键值, 可以减少hash发生冲突的次数, 所以会更快
        int primeNums[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};               
        unordered_map<unsigned long, vector<string>> tmp;
        for (int i = 0; i < (int) strs.size(); i++) {
            unsigned long key = 1;
            for (int j = 0; j < (int) strs[i].size(); j++)
                key *= primeNums[strs[i][j] - 'a'];  //一共26个质数
            tmp[key].push_back(strs[i]);
        }
        
        vector<vector<string>> res;
        for (auto const& item : tmp) {
            res.push_back(item.second);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	// vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs{"aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccdddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeefffffffffffffffffffffggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkklllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnooooooooooooooooooooopppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrssssssssssssssssssssstttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzz","aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffgggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnooooooooooooooooooooooppppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrrssssssssssssssssssssssttttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzz"};
	cout << Solution().groupAnagrams(strs) << endl;

	return 0;
}
