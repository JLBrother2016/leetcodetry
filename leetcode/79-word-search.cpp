#include "../leetcodeutil.h"

class Solution {
// 这是一道搜索题目, 利用DFS来进行求解
public:
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        if(h == 0 || w == 0) return false;
        for(int i = 0; i < h; ++i) {
        	for(int j = 0; j < w; ++j) { //board的每个位置都有可能是起点
        		if(search(board, word, 0, j, i, h, w)) {
        			return true;
        		}
        	}
        }

        return false;
    }
private:
	bool search(vector<vector<char>>& board, 
				string& word, int d, int x, 
				int y, int h, int w) {
		if(x == w || y == h || x < 0 || y < 0 || word[d] != board[y][x]) {
			return false;
		}
		if(d == word.length() - 1) { //找到了字符串中的最后一个元素
			return true;
		}
		char cur = board[y][x];
		board[y][x] = 0;
		bool found = search(board, word, d+1, x+1, y, h, w) ||
			   		 search(board, word, d+1, x-1, y, h, w) ||
			   		 search(board, word, d+1, x, y+1, h, w) ||
			   		 search(board, word, d+1, x, y-1, h, w);
		board[y][x] = cur;

		return found;
	}
};

int main(int argc, char const *argv[])
{
	vector<vector<char>> board{{'A','B','C','E'},
							   {'S','F','C','S'},
							   {'A','D','E','E'}};
	string str = "SEE";
	cout << Solution().exist(board, str) << endl;

	return 0;
}
