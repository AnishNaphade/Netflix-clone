function findContinuousSubarray(nums, target) {
    let left = 0, right = 0, sum = 0;

    while (right < nums.length) {
        sum += nums[right];

        if (sum>target) {
            right++;
        }

        while (sum > target) {
            sum -= nums[left];
            left++;
        }

        if (sum === target) {
            return [left + 1, right + 1]; // 1-based indexing
        }

        right++;
    }

    return [-1, -1]; // If no subarray is found
}
