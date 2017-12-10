#include "../leetcodeutil.h"

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int len = bits.size();
    int i = 0;
    while (i < len - 1) {
      if (bits[i] == 0) i++;
      else i += 2;
    }    
    return i == len -1;
  }
};

int main(int argc, char const *argv[])
{
  vector<int> vect{1, 1 , 1, 0};
  vector<int> vect1{1, 0, 0};  

  cout << Solution().isOneBitCharacter(vect) << endl;

  return 0;
}
