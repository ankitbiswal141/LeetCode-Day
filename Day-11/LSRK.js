function isRepeatedSubsequence(s, seq, k) {
  let pos = 0;
  for (let i = 0; i < k; i++) {
      for (let c of seq) {
          pos = s.indexOf(c, pos);
          if (pos === -1) return false;
          pos++; // Move past current character
      }
  }
  return true;
}

function longestSubsequenceRepeatedK(s, k) {
  const freq = new Array(26).fill(0);
  for (let c of s) {
      freq[c.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }

  const availableChars = [];
  for (let i = 0; i < 26; i++) {
      if (freq[i] >= k) {
          availableChars.push(String.fromCharCode('a'.charCodeAt(0) + i));
      }
  }

  let result = "";
  let queue = [""];

  while (queue.length > 0) {
      const curr = queue.shift();

      for (let c of availableChars) {
          const next = curr + c;

          if (isRepeatedSubsequence(s, next, k)) {
              if (
                  next.length > result.length ||
                  (next.length === result.length && next > result)
              ) {
                  result = next;
              }
              queue.push(next);
          }
      }
  }

  return result;
}

// Example usage
console.log(longestSubsequenceRepeatedK("letslets", 2)); // Output: "lets"