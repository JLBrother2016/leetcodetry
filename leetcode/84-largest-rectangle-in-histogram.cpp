#include "../leetcodeutil.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0); // 添加虚拟矩形条
        stack<int> st;       // 用栈来进行求解
        int n = height.size();
        int maxArea = 0;
        int h, w;

        for (int i = 0; i < n; i++) {
            // 如果栈还是空的或者栈顶指向的元素比当前元素小, 升续排列
            if (st.empty() || height[st.top()] < height[i])
                st.push(i);
            else {  //当前值比较小
                while (!st.empty() && height[i] <= height[st.top()]) {
                    h = height[st.top()]; //取出栈顶的位置, 前一个位置
                    st.pop();   //如果栈为空了重新计算, 如果不为空找到间隔
                    w = st.empty() ? i : i - (st.top() + 1);
                    maxArea = max(maxArea, h * w);  //寻找最大的矩形面积
                }
                st.push(i);  //把访问过的点放入到栈中  
            }
        }

        return maxArea;
    }  
};

int main(int argc, char const *argv[])
{
	vector<int> h{2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(h) << endl;

	return 0;
}
