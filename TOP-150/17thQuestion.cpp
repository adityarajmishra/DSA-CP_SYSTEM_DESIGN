class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0, currentGas = 0;
        int startStation = 0;

        for (int i = 0; i < n; ++i) {
            totalGas += gas[i] - cost[i];
            currentGas += gas[i] - cost[i];

            // If running out of gas, reset the starting station and current gas
            if (currentGas < 0) {
                startStation = i + 1;
                currentGas = 0;
            }
        }

        // If the total gas is negative, it means it's impossible to complete the circuit
        return totalGas >= 0 ? startStation : -1;
    }
};