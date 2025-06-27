#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool isRepeatedSubsequence(const string& s, const string& seq, int k) {
    int pos = 0;
    for (int i = 0; i < k; ++i) {
        for (char c : seq) {
            pos = s.find(c, pos);
            if (pos == string::npos) return false;
            ++pos; // Move past current character
        }
    }
    return true;
}

string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    vector<char> availableChars;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (freq[c - 'a'] >= k) {
            availableChars.push_back(c);
        }
    }

    string result = "";
    queue<string> q;
    q.push("");

    while (!q.empty()) {
        string curr = q.front(); q.pop();

        for (char c : availableChars) {
            string next = curr + c;

            if (isRepeatedSubsequence(s, next, k)) {
                if (next.length() > result.length() ||
                    (next.length() == result.length() && next > result)) {
                    result = next;
                }
                q.push(next);
            }
        }
    }

    return result;
}

int main() {
    cout << longestSubsequenceRepeatedK("letslets", 2) << endl; // Output: lets
    return 0;
}