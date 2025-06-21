#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    for (char ch : word) {
        freq[ch - 'a']++;
    }
    sort(freq.begin(), freq.end());

    int i = 0;
    while (i < 26 && freq[i] == 0) i++;

    int ans = INT_MAX;
    for (; i < 26; i++) {
        int x = freq[i];
        int ops = 0;
        for (int j = i; j < 26; j++) {
            int y = freq[j];
            if (y == 0) continue;
            if (y - x > k) {
                ops += y - x - k;
            } else if (y < x) {
                ops += y;
            }
        }
        ans = min(ans, ops);
    }
    return ans;
}

int main() {
    string word = "aabbcc";
    int k = 1;
    cout << "Minimum deletions: " << minimumDeletions(word, k) << endl;
    return 0;
}