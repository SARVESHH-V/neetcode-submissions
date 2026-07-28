class Solution {
public:
    int demo(vector<int> &nums, int s,int e){
        int n = e-s+1;
        if(n<=0) return 0;
        if(n==1) return nums[s];
        vector<int> dp(n);
        dp[0] = nums[s];
        dp[1] = max(nums[s],nums[s+1]);
        for(int i=2;i<n;i++){
            dp[i] = max(nums[s+i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int a = demo(nums,0,n-2);
        int b = demo(nums,1,n-1);

        int ans = max(a,b);
        return ans;
    }
};
