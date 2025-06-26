int longestSubsequence(string s, int k) {
  int length = 0;
  int value = 0;

  for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '0') {
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