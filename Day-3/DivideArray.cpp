#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    // Form sub-arrays of size 3
    for (int i = 0; i < nums.size(); i += 3) {
        // Check if the difference condition is met
        if (nums[i + 2] - nums[i] > k) {
            return {};  // return an empty array if the condition is not met
        }
        result.push_back({nums[i], nums[i + 1], nums[i + 2]});
    }

    return result;
}

int main() {
    vector<int> nums1 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k1 = 2;
    vector<int> nums2 = {2, 4, 2, 2, 5, 2};
    int k2 = 2;
    vector<int> nums3 = {4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11};
    int k3 = 14;

    // Test cases
    vector<vector<int>> result1 = divideArray(nums1, k1);
    vector<vector<int>> result2 = divideArray(nums2, k2);
    vector<vector<int>> result3 = divideArray(nums3, k3);

    // Print results
    for (const auto& group : result1) {
        for (int num : group) {
            cout << num << " ";
        }
        cout << endl;
    }

    for (const auto& group : result2) {
        for (int num : group) {
            cout << num << " ";
        }
        cout << endl;
    }

    for (const auto& group : result3) {
        for (int num : group) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
