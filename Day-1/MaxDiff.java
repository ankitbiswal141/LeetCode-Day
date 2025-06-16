class MaxDiff {
    public int maximumDifference(int[] nums) {
        int minValue = nums[0];  // First element as the minimum value
        int maxDifference = -1;  // Set maxDifference to -1 (indicating no valid pair)

        for (int j = 1; j < nums.length; j++) {
            if (nums[j] > minValue) {
                // Update with the maximum differnce
                maxDifference = Math.max(maxDifference, nums[j] - minValue);
            }
            // Update with minimum of the current value and nums[j]
            minValue = Math.min(minValue, nums[j]);
        }

        return maxDifference;
    }
}