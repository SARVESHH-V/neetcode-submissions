class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;

        for(int i=0;i<nums.size();i++){
            mp.insert(nums[i]);
        }
        int longest = 0;


        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i]-1)==0){
                int current = nums[i];
                int count = 1;

                while(mp.count(current+1)){
                    count++;
                    current++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};
