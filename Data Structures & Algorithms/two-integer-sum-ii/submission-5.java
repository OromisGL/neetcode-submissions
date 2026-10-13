class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0, rigth = numbers.length - 1;

        while (left < rigth) {
            int sum = numbers[rigth] + numbers[left];
            if (sum == target) {
                return new int [] {left + 1, rigth + 1};
            } else if (sum < target) {
                left++;
            } else {
                rigth--;
            }
        }
        return new int[] {0};
    }
}
