class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> numIndex;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (numIndex.find(val) != numIndex.end()) {
            return false;  // Element already exists
        }

        nums.push_back(val);
        numIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (numIndex.find(val) == numIndex.end()) {
            return false;  // Element does not exist
        }

        int lastNum = nums.back();
        int indexToRemove = numIndex[val];

        nums[indexToRemove] = lastNum;
        numIndex[lastNum] = indexToRemove;

        nums.pop_back();
        numIndex.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
};