class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n,1),suffix(n,1);

        for(int i =1,j=n-2 ;i<n;i++,j--){
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[j]=nums[j+1]*suffix[j+1];
        }
        vector<int> ans(n);

        for(int k=0;k<n;k++){
            ans[k]=prefix[k]*suffix[k];
        }
        return ans;
    }
};
