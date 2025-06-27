class LSRK {

    private boolean isRepeatedSubsequence(String s, String seq, int k) {
        int pos = 0;
        for (int i = 0; i < k; i++) {
            for (char c : seq.toCharArray()) {
                pos = s.indexOf(c, pos);
                if (pos == -1) return false;
                pos++; // Move past this character
            }
        }
        return true;
    }

    public String longestSubsequenceRepeatedK(String s, int k) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Build list of characters that appear at least k times
        List<Character> availableChars = new ArrayList<>();
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c - 'a'] >= k) {
                availableChars.add(c);
            }
        }

        // Try building subsequences in BFS order (from longest to shortest)
        Queue<String> queue = new LinkedList<>();
        queue.offer("");

        String result = "";

        while (!queue.isEmpty()) {
            String curr = queue.poll();

            for (char c : availableChars) {
                String next = curr + c;

                if (isRepeatedSubsequence(s, next, k)) {
                    // If it's valid, add to queue
                    queue.offer(next);

                    // Update result if lexicographically larger or longer
                    if (next.length() > result.length() ||
                        (next.length() == result.length() && next.compareTo(result) > 0)) {
                        result = next;
                    }
                }
            }
        }

        return result;
    }
}