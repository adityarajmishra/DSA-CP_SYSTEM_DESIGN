class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<pair<int, int>, int>> jobs;

        for (int i = 0; i < n; ++i) {
            jobs.push_back({{endTime[i], startTime[i]}, profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n);
        dp[0] = jobs[0].second;

        for (int i = 1; i < n; ++i) {
            int includeProfit = jobs[i].second;
            int l = binarySearch(jobs, i);
            if (l != -1) {
                includeProfit += dp[l];
            }

            dp[i] = max(dp[i - 1], includeProfit);
        }

        return dp[n - 1];
    }

private:
    int binarySearch(const vector<pair<pair<int, int>, int>>& jobs, int index) {
        int low = 0, high = index - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (jobs[mid].first.first <= jobs[index].first.second) {
                if (jobs[mid + 1].first.first <= jobs[index].first.second) {
                    low = mid + 1;
                } else {
                    return mid;
                }
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};