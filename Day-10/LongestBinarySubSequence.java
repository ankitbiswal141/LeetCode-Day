class LongestBinarySubSequence {
    /**
     * Returns the length of the longest subsequence with a decimal value less than or equal to k.
     *
     * @param s The binary string.
     * @param k The upper bound for the decimal value of the subsequence.
     * @return The length of the longest valid subsequence.
     */
    public int longestSubsequence(String s, int k) {
        int longestLength = 0;  // Tracks the length of the valid subsequence
        int decimalValue = 0;   // Tracks the current value of the subsequence

        // Iterate over the string in reverse (least significant to most significant bits)
        for (int index = s.length() - 1; index >= 0; --index) {
            char bit = s.charAt(index);

            if (bit == '0') {
                // Always include '0' since it doesn't increase the value
                longestLength++;
            } else {
                // Check if adding this '1' keeps the value within k
                // Also ensure we don't exceed 30 bits to avoid integer overflow
                if (longestLength < 30 && (decimalValue | (1 << longestLength)) <= k) {
                    decimalValue |= (1 << longestLength);
                    longestLength++;
                }
            }
        }

        return longestLength;
    }
}