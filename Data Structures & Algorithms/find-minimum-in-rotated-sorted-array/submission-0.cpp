class Solution {
public:
    int findMin(vector<int> &nums) {
        int k = nums.size();

        int l=0;
        int r=k-1;
        int ans = 0;

        while(l<r){
            int mid = l+(r-l)/2;

            if(nums[mid]>nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};
