class Solution {
public:
    void helper(int i,vector<int>& nums,int n,vector<vector<int>> &ans,vector<int> &con){
        if(i==n){
            ans.push_back(con);
            
            return;
        }
        con.push_back(nums[i]);
        helper(i+1,nums,n,ans,con);
        con.pop_back();
        while (i + 1 < n && nums[i] == nums[i + 1]) {
        i++;
        }
        helper(i+1,nums,n,ans,con);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> con;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        helper(0, nums, n, ans,con);
        
        return ans;
    }
};