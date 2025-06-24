#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    // Step 1: Identify all positions where nums[i] == key
    vector<int> keyIndices;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == key) {
            keyIndices.push_back(i);
        }
    }

    // Step 2: Initialize the result set
    set<int> result;

    // Step 3: For each key index, add all indices within the range of k to the result
    for (int idx : keyIndices) {
        for (int i = max(0, idx - k); i <= min((int)nums.size() - 1, idx + k); ++i) {
            result.insert(i);
        }
    }

    // Step 4: Convert the set to a vector and return it
    vector<int> resultList(result.begin(), result.end());
    return resultList;
}

int main() {
    // Test case 1
    vector<int> nums1 = {3, 4, 9, 1, 3, 9, 5};
    int key1 = 9, k1 = 1;
    vector<int> res1 = findKDistantIndices(nums1, key1, k1);
    for (int i : res1) cout << i << " ";  // Output: 1 2 3 4 5 6
    cout << endl;

    // Test case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int key2 = 2, k2 = 2;
    vector<int> res2 = findKDistantIndices(nums2, key2, k2);
    for (int i : res2) cout << i << " ";  // Output: 0 1 2 3 4
    cout << endl;

    return 0;
}
