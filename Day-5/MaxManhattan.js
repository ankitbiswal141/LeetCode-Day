function maxManhattanDistance(s, k) {
  // Count how many times each direction occurs
  let N = 0, S = 0, E = 0, W = 0;
  let maxDist = 0;

  // Iterate over each move in the string
  for (let i = 0; i < s.length; i++) {
      const move = s[i];
      switch (move) {
          case 'N': N++; break;
          case 'S': S++; break;
          case 'E': E++; break;
          case 'W': W++; break;
      }

      // Greedy step: try to use up to k changes to maximize net movement

      // Vertical movement: try to reduce min(N, S) by converting to one direction
      let minVert = Math.min(N, S);
      let usedVert = Math.min(k, minVert);
      let remaining = k - usedVert;

      // Horizontal movement: try to reduce min(E, W) by converting to one direction
      let minHoriz = Math.min(E, W);
      let usedHoriz = Math.min(remaining, minHoriz);

      // Compute net distances after applying changes
      let verticalDist = Math.abs(N - S) + 2 * usedVert;
      let horizontalDist = Math.abs(E - W) + 2 * usedHoriz;
      let totalDist = verticalDist + horizontalDist;

      // Update maximum distance found so far
      maxDist = Math.max(maxDist, totalDist);
  }

  return maxDist;
}

// Example test cases
console.log("Example 1:", maxManhattanDistance("NWSE", 1)); // Output: 3
console.log("Example 2:", maxManhattanDistance("NSWWEW", 3)); // Output: 6