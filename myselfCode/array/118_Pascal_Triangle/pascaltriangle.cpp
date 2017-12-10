#include "../leetcodeutil.h"

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//       vector<vector<int>> result(numRows);
//         for(int i = 0; i < numRows; ++i) {
//           result[i].resize(i + 1);
//           result[i][0] = result[i][i] = 1;

//           for(int j = 1; j < i; j++) {
//             result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
//           }
//         }
//       return result;
//     }
// };

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

        
        if(numRows == 0)
            return result;
        
        
    vector<int> temp;
    temp.push_back(1);
    result.push_back(temp);
        
        if(numRows == 1)
            return result;
    temp.push_back(1);
    result.push_back(temp);
    temp.clear();

        if(numRows == 2)
            return result;
    for (int i = 2; i < numRows; i++)
    {
        for (int j = 0; j < (i+1); j++)
        {
            if (j == 0)
            {
                temp.push_back(1);
            }
            else if (j == i)
            {
                temp.push_back(1);
                result.push_back(temp);
                temp.clear();
            }
            else
            {
                vector<int> prev = result[i - 1];
                temp.push_back(prev[j] + prev[j - 1]);
            }
        }
    }

    return result;
    }
};

int main(int argc, char const *argv[])
{
  

  return 0;
}