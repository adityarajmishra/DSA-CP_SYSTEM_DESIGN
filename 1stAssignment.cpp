#include <vector>

#include <algorithm>


using namespace std;

class Solution {

public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    unordered_map<int, vector<vector<int>>> memo; // Memoization to store previously computed combinations for each target
    return combinationSumHelper(candidates, target, 0, memo);
  }

private:
  vector<vector<int>> combinationSumHelper(const vector<int>& candidates, int target, int index, unordered_map<int, vector<vector<int>>>& memo) {
    if (target == 0) {
      return {{}}; // Empty combination for target 0
    }

    if (memo.count(target) > 0) { // Check memoization for previously computed combinations
      return memo[target];
    }

    vector<vector<int>> result;
    for (int i = index; i < candidates.size() && target >= candidates[i]; ++i) {
      // Explore combinations with current candidate
      vector<vector<int>> subCombinations = combinationSumHelper(candidates, target - candidates[i], i, memo);
      for (auto& subCombination : subCombinations) {
        subCombination.push_back(candidates[i]); // Add current candidate to each sub-combination
        result.push_back(subCombination);
      }
    }

    memo[target] = result; // Store computed combinations for future use
    return result;
  }
};