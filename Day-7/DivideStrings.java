class DivideStrings {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int totalGroups = (int) Math.ceil((double) n / k);
        String[] result = new String[totalGroups];

        for (int i = 0; i < totalGroups; i++) {
            int start = i * k;
            int end = Math.min(start + k, n);
            String group = s.substring(start, end);

            // If group length is less than k, add fill characters
            if (group.length() < k) {
                group += String.valueOf(fill).repeat(k - group.length());
            }

            result[i] = group;
        }

        return result;
    }
}