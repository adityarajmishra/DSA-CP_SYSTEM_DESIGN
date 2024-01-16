class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int hIndex = 0;

        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                // The number of papers with at least hIndex citations is hIndex
                hIndex = i + 1;
            } else {
                // No need to check further, as the remaining papers will have even fewer citations
                break;
            }
        }

        return hIndex;
    }
};