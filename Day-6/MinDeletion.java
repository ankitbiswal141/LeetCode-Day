import java.util.*;

public class MinDeletion {
    public static int minDeletionsToKSpecial(String word, int k) {
        // Step 1: Count frequency of each character
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : word.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        // Step 2: Extract and sort the frequencies
        List<Integer> frequencies = new ArrayList<>(freqMap.values());
        Collections.sort(frequencies);

        // Step 3: Try each frequency as the base, and adjust others accordingly
        int minDeletions = Integer.MAX_VALUE;
        for (int i = 0; i < frequencies.size(); i++) {
            int base = frequencies.get(i);
            int deletions = 0;

            for (int j = 0; j < frequencies.size(); j++) {
                int f = frequencies.get(j);
                if (f < base) {
                    // Remove the whole character frequency
                    deletions += f;
                } else if (f > base + k) {
                    // Reduce to base + k
                    deletions += (f - (base + k));
                }
            }

            minDeletions = Math.min(minDeletions, deletions);
        }

        return minDeletions;
    }

    // Example usage
    public static void main(String[] args) {
        System.out.println(minDeletionsToKSpecial("aabcaba", 0));       // Output: 3
        System.out.println(minDeletionsToKSpecial("dabdcbdcdcd", 2));   // Output: 2
        System.out.println(minDeletionsToKSpecial("aaabaaa", 2));       // Output: 1
    }
}