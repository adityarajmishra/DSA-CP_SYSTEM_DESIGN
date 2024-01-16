class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        for (const std::string& str : strs) {
            std::string key = str;
            std::sort(key.begin(), key.end()); // Sort the characters in the string to create a unique key

            anagramGroups[key].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
    }
};