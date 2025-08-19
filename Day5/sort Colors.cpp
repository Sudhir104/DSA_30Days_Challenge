class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
               
            }
            else if(nums[mid]==0){
               swap(nums[mid],nums[low]);
               low++;
               mid++;
            }
            else{
                mid++;
            }
        }
    }
};
// 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        int two=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)  zero++;
            else if(nums[i]==1) one++;
            else two++;

        }
        for(int i=0;i<n;i++){
            if(i<zero) nums[i]=0;
            else if(i<(zero+one)) nums[i]=1;
            else nums[i]=2;
        }
     
     return;
    }
};