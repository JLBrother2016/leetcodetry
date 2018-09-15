#include "../leetcodeutil.h"

class Solution {
// 贪心来求解这道题, 先处理次数出现最多的那个任务, 先确定好高频任务, 再安排那些低频任务
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(char& task : tasks) {
            ++cnt[task - 'A'];
        }
        const int max_count = *max_element(cnt.begin(), cnt.end());  // 3
        size_t ans = (max_count - 1) * (n + 1);  // 6
        // count_if满足函数对象功能的元素个数, 频率为3的个数为2, 所以ans等于8
        ans += count_if(cnt.begin(), cnt.end(), [max_count](int c) {return c == max_count;});

        return max(tasks.size(), ans);
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());   //排序, 数组后面的就是出现次数最多的
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;    // 可能出现次数出现最多的并列
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};

// 如果有多个任务出现次数相同，那么将其整体放一起，就像上面的第二个例子中的CE一样，那么此时每个part中的空位个数就是n - (mxCnt - 1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mx = 0, mxCnt = 0;
        vector<int> cnt(26, 0);        
        for (char task : tasks) {
            ++cnt[task - 'A'];
            if (mx == cnt[task - 'A']) {
                ++mxCnt;   // 统计相同的频率数
            } else if (mx < cnt[task - 'A']) {
                mx = cnt[task - 'A'];
                mxCnt = 1;
            }
        }
        int partCnt = mx - 1;
        int partLen = n - (mxCnt - 1);
        int emptySlots = partCnt * partLen;
        int taskLeft = tasks.size() - mx * mxCnt;
        int idles = max(0, emptySlots - taskLeft);
        return tasks.size() + idles;
    }
};
// 思路是建立一个优先队列，然后把统计好的个数都存入优先队列中，那么大的次数会在队列的前面
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0, cycle = n + 1;
        unordered_map<char, int> m;
        priority_queue<int> q;
        for (char c : tasks) ++m[c];
        for (auto a : m) q.push(a.second);
        while (!q.empty()) {
            int cnt = 0;
            vector<int> t;
            for (int i = 0; i < cycle; ++i) {
                if (!q.empty()) {
                    t.push_back(q.top()); 
                    q.pop();
                    ++cnt;
                }
            }
            for (int d : t) {
                if (--d > 0) q.push(d);
            }
            res += q.empty() ? cnt : cycle;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<char> vc{'A','A','A','B','B','B'};
    cout << Solution().leastInterval(vc, 2) << endl;

    return 0;
}

