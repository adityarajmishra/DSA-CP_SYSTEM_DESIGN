class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> directories;
        string directory;

        // Split the input path using '/'
        while (getline(ss, directory, '/')) {
            if (directory == "..") {
                // Go one level up, pop from the stack if not empty
                if (!directories.empty()) {
                    directories.pop_back();
                }
            } else if (directory != "." && !directory.empty()) {
                // Ignore '.' and empty directories, push onto the stack
                directories.push_back(directory);
            }
        }

        // Construct the simplified path using the directories on the stack
        stringstream result;
        result << "/";
        for (const string& dir : directories) {
            result << dir << "/";
        }

        // Remove the trailing '/'
        string simplifiedPath = result.str();
        return simplifiedPath.size() > 1 ? simplifiedPath.substr(0, simplifiedPath.size() - 1) : simplifiedPath;
    }
};