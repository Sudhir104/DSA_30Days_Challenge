class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int currentsum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<n;i++){
            currentsum=max(nums[i],nums[i]+currentsum);
            maxsum=max(maxsum,currentsum);
        }
       return maxsum;
    }
};