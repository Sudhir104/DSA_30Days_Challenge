class Solution {
public:
    vector<vector<int>> generate(int nums) {
        vector<vector<int>> v;
       
        for(int i=0;i<nums;i++){
            vector<int> a(i+1,1); 
            v.push_back(a);
        }
        
        for(int i=2;i<nums;i++){
            for(int j=1;j<i;j++){
                v[i][j]=v[i-1][j]+v[i-1][j-1];
            }
        }
        return v;
    }
};