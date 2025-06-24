import java.util.*;

public class DistantIndices {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        // Step 1: Identify all positions where nums[i] == key
        List<Integer> keyIndices = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == key) {
                keyIndices.add(i);
            }
        }
        
        // Step 2: Initialize the result list
        Set<Integer> result = new HashSet<>();
        
        // Step 3: For each key index, add all indices within the range of k to the result
        for (int idx : keyIndices) {
            for (int i = Math.max(0, idx - k); i <= Math.min(nums.length - 1, idx + k); i++) {
                result.add(i);
            }
        }
        
        // Step 4: Convert the set to a sorted list and return it
        List<Integer> resultList = new ArrayList<>(result);
        Collections.sort(resultList);
        return resultList;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Test case 1
        int[] nums1 = {3, 4, 9, 1, 3, 9, 5};
        int key1 = 9;
        int k1 = 1;
        System.out.println(solution.findKDistantIndices(nums1, key1, k1));  // Output: [1, 2, 3, 4, 5, 6]

        // Test case 2
        int[] nums2 = {2, 2, 2, 2, 2};
        int key2 = 2;
        int k2 = 2;
        System.out.println(solution.findKDistantIndices(nums2, key2, k2));  // Output: [0, 1, 2, 3, 4]
    }
}
