class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        unordered_map<string, string> parent;
        unordered_map<string, unordered_set<string>> unions;

        // Helper function to find the ultimate parent using union-find
        auto find = [&](const string& email) -> string {
            string root = email;
            while (parent[root] != root) {
                root = parent[root];
            }

            // Path compression
            string temp = email;
            while (temp != root) {
                string next = parent[temp];
                parent[temp] = root;
                temp = next;
            }

            return root;
        };

        // Union function
        auto unite = [&](const string& email1, const string& email2) {
            string root1 = find(email1);
            string root2 = find(email2);

            if (root1 != root2) {
                parent[root1] = root2;
            }
        };

        // Initialization
        for (const auto& acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                emailToName[acc[i]] = acc[0];
                parent[acc[i]] = acc[i];
            }
        }

        // Perform unions based on common emails
        for (const auto& acc : accounts) {
            for (int i = 2; i < acc.size(); ++i) {
                unite(acc[i], acc[i - 1]);
            }
        }

        // Group emails by their ultimate parent
        for (const auto& acc : accounts) {
            for (int i = 1; i < acc.size(); ++i) {
                unions[find(acc[i])].insert(acc[i]);
            }
        }

        // Build the result
        vector<vector<string>> result;
        for (const auto& [root, emails] : unions) {
            vector<string> account(emails.begin(), emails.end());
            sort(account.begin(), account.end());
            account.insert(account.begin(), emailToName[root]);
            result.push_back(account);
        }

        return result;
    }
};