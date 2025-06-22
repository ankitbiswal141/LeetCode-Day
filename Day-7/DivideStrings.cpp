#include <vector>
#include <string>

std::vector<std::string> divideString(std::string s, int k, char fill) {
    std::vector<std::string> result;
    int n = s.length();
    for (int i = 0; i < n; i += k) {
        int end = i + k;
        std::string chunk = s.substr(i, k);
        if (end > n) {
            chunk += std::string(k - chunk.length(), fill);
        }
        result.push_back(chunk);
    }
    return result;
}