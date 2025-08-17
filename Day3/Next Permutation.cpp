class Solution {
public:
   void reversefun( vector<int>&nums,int i, int j){
    while(i<j){
         int temp;
   temp=nums[i];
   nums[i]=nums[j];
   nums[j]=temp;
     i++;
     j--;
       }
   }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
           if(nums[i]<nums[i+1]){
             pivot=i;
             break;
           }
        }
     if(pivot==-1){
        reversefun(nums,0,n-1);
        return;
     }
     for(int i=n-1;i>pivot;i--){
        if(nums[i]>nums[pivot]){
           swap(nums[i],nums[pivot]);
           break;
        }
     }
        reversefun(nums,pivot+1,n-1);
    }
};