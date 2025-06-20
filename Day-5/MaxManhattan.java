public class MaxManhattanDistance {
    public static int maxDistance(String s, int k) {
        int N = 0, S = 0, E = 0, W = 0;
        int ans = 0;

        for (char c : s.toCharArray()) {
            switch (c) {
                case 'N': N++; break;
                case 'S': S++; break;
                case 'E': E++; break;
                case 'W': W++; break;
            }

            // Greedy allocation: vertical first
            int verticalChanges = Math.min(k, Math.min(N, S));
            int remaining = k - verticalChanges;
            int horizontalChanges = Math.min(remaining, Math.min(E, W));

            int verticalDist = Math.abs(N - S) + 2 * verticalChanges;
            int horizontalDist = Math.abs(E - W) + 2 * horizontalChanges;

            ans = Math.max(ans, verticalDist + horizontalDist);
        }

        return ans;
    }

    public static void main(String[] args) {
        String s = "NWSE";
        int k = 1;
        System.out.println("Maximum Manhattan Distance: " + maxDistance(s, k)); // Output: 3
    }
}