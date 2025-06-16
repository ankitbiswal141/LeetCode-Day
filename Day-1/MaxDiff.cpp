#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int minValue = nums[0];  // First element as the minimum value
    int maxDifference = -1;  // Set maxDifference to -1 (indicating no valid pair)

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] > minValue) {
            // Update with the larger difference
            maxDifference = max(maxDifference, nums[j] - minValue);
        }
        // Update with minimum of the current value and nums[j]
        minValue = min(minValue, nums[j]);
    }

    return maxDifference;
}

int main() {
    // Test cases
    return 0;
}
