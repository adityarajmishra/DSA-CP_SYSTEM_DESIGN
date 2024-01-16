class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Initialize two arrays to store products from left and right
        vector<int> leftProducts(n, 1);
        vector<int> rightProducts(n, 1);

        // Calculate products from the left side
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            leftProducts[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // Calculate products from the right side
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            rightProducts[i] = rightProduct;
            rightProduct *= nums[i];
        }

        // Multiply left and right products to get the final result
        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = leftProducts[i] * rightProducts[i];
        }

        return result;
    }
};