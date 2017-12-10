#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public: vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (hash.find(complement) != hash.end()) {
            result.push_back(hash[complement]);
            result.push_back(i);            
            return result;
        }
        hash[nums[i]] = i;
    }
    return result;
  }
};

int main (int argc, char *argv[])
{
  int nums[3] = {3,2,4};
  int target = 6;
  vector<int> vnums;
  for(int i = 0; i < 3; ++i){
    vnums.push_back(nums[i]);
  }
  Solution s;
  vector<int> re = s.twoSum(vnums, target);

  for(int i = 0; i < 2; ++i)
    cout << re[i] << endl;

  return 0;
}
/*
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[] { map.get(complement), i };
        }
        map.put(nums[i], i);
    }
    throw new IllegalArgumentException("No two sum solution");
}
*/