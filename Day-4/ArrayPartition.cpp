#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arrayPartition(vector<int>& nums) {
    // Sort the array
    sort(nums.begin(), nums.end());

    int sum = 0;
    // Add every second element starting from index 0
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }

    return sum;
}

int main() {
  // Test cases here
}
