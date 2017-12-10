#include "../leetcodeutil.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        result[0] = 1;
        for(int i = 0; i < rowIndex + 1; ++i)
          for(int j = i; j >= 1; j--)
            result[j] += result[j-1];

        return result;
    }
};

// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> now;
//         for(int i = 0; i <= rowIndex; i++){
//             int tmp, carry = 0;
//             for(int j = 0; j < now.size(); j++){
//                 tmp = now[j];
//                 if(j == 0)
//                     now[j] = 1;
//                 else
//                     now[j] += carry;
//                 carry = tmp;
//             }
//             now.push_back(1);
//         }
//         return now;
//     }
// };

int main(int argc, char const *argv[])
{

  cout << Solution().getRow(3) << endl;

  return 0;
}