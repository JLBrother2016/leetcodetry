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
        // hash.insert(std::make_pair<int, int>(nums[i], i));
        // hash[nums[i]] = i;
        hash.emplace(nums[i], i);
    }
        
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        auto it = hash.find(complement);
        if ( it != hash.end() && it->second != i) {
            // result.push_back(hash[complement]);
            // result.push_back(i); 
            return {i, hash[complement]};           
            // return result;
        }
        hash[nums[i]] = i;
    }
    return {};
  }
};

int main (int argc, char *argv[])
{
  int target = 6;
  vector<int> vnums{3, 2, 4};

  class Solution s;
  vector<int> re = s.twoSum(vnums, target);

  for(int i = 0; i < 2; ++i)
    cout << re[i] << endl;

  return 0;
}


/*
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> map = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        map.put(nums[i], i);
    }
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement) && map.get(complement) != i) {
            return new int[] { i, map.get(complement) };
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
*/








