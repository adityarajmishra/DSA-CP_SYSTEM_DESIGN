class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if (n == 0) {
            return tasks.size();
        }

        std::unordered_map<char, int> taskCount;

        // Count the occurrences of each task
        for (char task : tasks) {
            taskCount[task]++;
        }

        // Sort the tasks based on their occurrences in descending order
        std::vector<int> counts;
        for (auto& entry : taskCount) {
            counts.push_back(entry.second);
        }
        std::sort(counts.begin(), counts.end(), std::greater<int>());

        // Calculate the idle slots
        int maxCount = counts[0];
        int idleSlots = (maxCount - 1) * n;

        // Distribute the remaining tasks among the idle slots
        for (int i = 1; i < counts.size(); i++) {
            idleSlots -= std::min(counts[i], maxCount - 1);
        }

        // Return the total time required
        return std::max((int)tasks.size(), (int)tasks.size() + idleSlots);
    }
};