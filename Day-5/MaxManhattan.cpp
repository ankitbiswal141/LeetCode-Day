#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to compute maximum Manhattan distance
int maxManhattanDistance(const string& s, int k) {
    int N = 0, S = 0, E = 0, W = 0;
    int maxDist = 0;

    for (char move : s) {
        switch (move) {
            case 'N': N++; break;
            case 'S': S++; break;
            case 'E': E++; break;
            case 'W': W++; break;
        }

        // Greedy strategy: use k changes to reduce opposing directions

        // Vertical direction optimization
        int minVert = min(N, S);
        int usedVert = min(k, minVert);
        int remaining = k - usedVert;

        // Horizontal direction optimization
        int minHoriz = min(E, W);
        int usedHoriz = min(remaining, minHoriz);

        // Compute current net vertical and horizontal distances
        int verticalDist = abs(N - S) + 2 * usedVert;
        int horizontalDist = abs(E - W) + 2 * usedHoriz;
        int totalDist = verticalDist + horizontalDist;

        // Update the maximum distance found so far
        maxDist = max(maxDist, totalDist);
    }

    return maxDist;
}

// Main function with example test cases
int main() {
    string s1 = "NWSE";
    int k1 = 1;
    cout << "Example 1: " << maxManhattanDistance(s1, k1) << endl; // Output: 3

    string s2 = "NSWWEW";
    int k2 = 3;
    cout << "Example 2: " << maxManhattanDistance(s2, k2) << endl; // Output: 6

    return 0;
}