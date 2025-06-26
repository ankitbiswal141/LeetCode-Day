function longestSubsequence(s, k) {
  let length = 0;
  let value = 0;

  for (let i = s.length - 1; i >= 0; i--) {
      if (s[i] === '0') {
          length++;
      } else {
          if (length < 30 && (value | (1 << length)) <= k) {
              value |= (1 << length);
              length++;
          }
      }
  }

  return length;
}