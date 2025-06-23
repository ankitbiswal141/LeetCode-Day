#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string toBaseK(long long num, int k) {
    string res = "";
    while (num > 0) {
        res = char('0' + num % k) + res;
        num /= k;
    }
    return res;
}

bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

vector<long long> generatePalindromes(int length) {
    vector<long long> res;
    int halfLen = (length + 1) / 2;
    long long start = pow(10, halfLen - 1);
    long long end = pow(10, halfLen);

    for (long long i = start; i < end; ++i) {
        string firstHalf = to_string(i);
        string secondHalf = firstHalf.substr(0, length % 2 == 0 ? firstHalf.size() : firstHalf.size() - 1);
        reverse(secondHalf.begin(), secondHalf.end());
        string pal = firstHalf + secondHalf;
        res.push_back(stoll(pal));
    }
    return res;
}

long long kMirror(int k, int n) {
    long long sum = 0;
    int count = 0, length = 1;

    while (count < n) {
        vector<long long> pals = generatePalindromes(length);
        for (long long num : pals) {
            if (isPalindrome(toBaseK(num, k))) {
                sum += num;
                count++;
                if (count == n) return sum;
            }
        }
        length++;
    }
    return sum;
}

int main() {
    cout << kMirror(2, 20) << endl;  // Example
    return 0;
}
