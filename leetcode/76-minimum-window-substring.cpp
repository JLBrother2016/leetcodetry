#include "../leetcodeutil.h"

class Solution {
// 这道题是很典型的一道题, 题型叫做sliding window
// 双指针，一个是从前往后进行遍历, 一个是记录起始位置
public:
    string minWindow(string s, string t) {
        // if(s.length() == 0 || t.length() == 0) {
        // 	return "";
        // }
        // if(s.length() < t.length()) return "";
        // vector<int> count_map(256, 0);
        // int slow = 0, index = 0, matchCount = 0;
        // int min_len = INT_MAX;
        // int subNum = 0;

        // for(char &ch : t) {
        //     if(count_map[ch] == 0) {
        //         count_map[ch] = 1;
        //         ++subNum;
        //     }
        // 	++count_map[ch];
        // }
        // // cout << count_map << endl;
        // // cout << s[slow++] << " " << slow << endl;

        // for(int fast = 0; fast < s.length(); ++fast) {
        //     --count_map[s[fast]];
        // 	if(count_map[s[fast]] < 0) { //t中没有的元素
        // 		continue;    //直接继续执行
        // 	}
        // 	if(count_map[s[fast]] == 0) { //匹配到一个字符
        // 		++matchCount;
        // 	}

        // 	while(matchCount == subNum) {
        // 		// 查找一个合法的子串
        // 		if(fast - slow + 1 < min_len) {
        // 			min_len = fast - slow + 1;
        // 			index = slow;
        // 		}

        //         if(count_map[s[slow++]]++ == 1) {
        //             --matchCount;
        //         }
        // 		// if(count_map[s[slow]] == INT_MIN) {
        // 		// 	++slow;    //没有该元素的化指针移动一位, 并继续查找
        // 		// 	continue;
        // 		// }
        // 		// if(count_map[s[slow]] == 0) {
        // 		// 	count_map[s[slow]] = 1;
        // 		// 	// ++slow;
        // 		// 	--matchCount;
        // 		// }

        // 	}
        // }
        // cout << slow << endl;
        // cout << min_len << endl;

        // return min_len == INT_MAX ? "" : s.substr(slow-1, slow + min_len);
        if(!s.size() || s.size() < t.size()){
            return "";
        }
        
        vector<int> curcnt(260), tcnt(260);
        for(int i = 0; i < t.size(); ++ i){
            ++ tcnt[t[i]];
        }
        
        int l = 0, r = 0, len = INT_MAX, num = 0, sta;
        for(int i = 0; i < s.size(); ++ i){
            if(tcnt[s[i]] > 0){   //如果是t字符串中的字母
                ++ curcnt[s[i]];  //当前已经访问了该字木这么多次
                if(curcnt[s[i]] <= tcnt[s[i]])
                    ++ num; //总的字符个数
            }
            
            if(num == t.size()){  //如果访问了字符串t的长度
                r = i;  //快指针的位置
                while(curcnt[s[l]] > tcnt[s[l]] || tcnt[s[l]] == 0){
                    -- curcnt[s[l]];  //当前访问的数减1
                    ++ l; //左指针向右移动一位
                }  //保留最小有效长度
                if(len > r - l + 1){
                    len = r - l + 1;
                    sta = l;
                }
            }
        }
        
        return len == INT_MAX ? "" : s.substr(sta, len);
    }
};
// class Solution {
// public:
//     string minWindow(string s, string t) {
//             vector<int> map(128,0);
//             for(auto c: t) map[c]++;
//             int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
//             while(end<s.size()){
//                 if(map[s[end++]]-->0) counter--; //in t 先访问s[end]，再+1
//                 while(counter==0){ //valid
//                     if(end-begin<d)  d=end-(head=begin);
//                     if(map[s[begin++]]++==0) counter++;  //make it invalid
//                 }  
//             }
//             return d==INT_MAX? "":s.substr(head, d);
//     }
// };




int main(int argc, char const *argv[])
{
	cout << Solution().minWindow("ADOBECODEBANC", "ABC") << endl;
	
	return 0;
}
