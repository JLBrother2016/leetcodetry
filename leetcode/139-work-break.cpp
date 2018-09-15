#include "../leetcodeutil.h"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        // dp[i]表示前i个字符能否完美切分
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;   //空字符串是可以任意分割的
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(find(wordDict.begin(), wordDict.end(), word)!= wordDict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};

int main(int argc, char const *argv[])
{
    

    return 0;
}
