#include "../leetcodeutil.h"

/*class Solution {
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
};*/
/*class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size() - 1;
        while (i < n) i += bits[i] + 1;
        return i == n;
    }
};*/
/*class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return dfs(bits, 0);        
    }
private:
    bool dfs(vector<int>& bits, int idx) {
        if (idx == bits.size()) return false;
        if (idx == bits.size() - 1 && bits[idx] == 0) return true;
        if (bits[idx] == 1) return dfs(bits, idx + 2);
        else return dfs(bits, idx + 1);
    }

};*/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        return isOneBitCharacter(bits, 0);
    }
    
    bool isOneBitCharacter(vector<int>& bits, int i) {
        if(bits.size() - i == 1) {
            return bits[i] == 0;
        } else if(bits.size() - i == 0)
            return false;
        
        bool isOk = false;
        
        if(bits[i] == 1) {
            isOk = isOneBitCharacter(bits, i + 2);
        } else {
            isOk = isOneBitCharacter(bits, i + 1);
        }
        return isOk;
    }
};


int main(int argc, char const *argv[])
{
  vector<int> vect{1, 1 , 1, 0};
  vector<int> vect1{1, 0, 0};  

  cout << Solution().isOneBitCharacter(vect1) << endl;

  return 0;
}
