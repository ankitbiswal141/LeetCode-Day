import java.util.Arrays;

public class ArrayPartition {
    
    public static int partitionArray(int[] nums, int k) {
        // Sort the array to allow grouping in ascending order
        Arrays.sort(nums);
        
        int subsequences = 0;
        int i = 0;
        
        // Iterate through the sorted array
        while (i < nums.length) {
            subsequences++;  // Start a new subsequence
            int minVal = nums[i];  // The first element in the subsequence
            
            // Try to extend the subsequence while the difference is <= k
            while (i < nums.length && nums[i] - minVal <= k) {
                i++;
            }
        }
        
        return subsequences;
    }

    public static void main(String[] args) {
        // Test Cases here
    }
}
