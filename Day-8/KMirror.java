class KMirror {

    private static String toBaseK(long num, int k) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            sb.append(num % k);
            num /= k;
        }
        return sb.reverse().toString();
    }

    private static boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }

    private static List<Long> generatePalindromes(int length) {
        List<Long> res = new ArrayList<>();

        int halfLen = (length + 1) / 2;
        int start = (int)Math.pow(10, halfLen - 1);
        int end = (int)Math.pow(10, halfLen);

        for (int i = start; i < end; i++) {
            String firstHalf = String.valueOf(i);
            String fullPalindrome = firstHalf;

            // If length is even, mirror entire firstHalf
            // If odd, mirror all except last digit
            String secondHalf = new StringBuilder(firstHalf.substring(0, length % 2 == 0 ? firstHalf.length() : firstHalf.length() - 1)).reverse().toString();
            fullPalindrome += secondHalf;

            res.add(Long.parseLong(fullPalindrome));
        }

        return res;
    }

    public long kMirror(int k, int n) {
        long sum = 0;
        int length = 1;
        int count = 0;

        while (count < n) {
            List<Long> palindromes = generatePalindromes(length);
            for (long num : palindromes) {
                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    count++;
                    if (count == n) break;
                }
            }
            length++;
        }

        return sum;
    }
}
