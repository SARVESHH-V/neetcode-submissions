class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (abs(target) > totalSum) {
            return 0;
        }

        if ((totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetTarget = (totalSum + target) / 2;

        vector<int> dp(subsetTarget + 1, 0);

        dp[0] = 1;

        for (int num : nums) {
            for (int sum = subsetTarget; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[subsetTarget];
    }
};