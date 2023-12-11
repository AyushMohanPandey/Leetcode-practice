class Solution {
public:
    void helper(int i, vector<int>& nums, vector<vector<int>> &ans, vector<int> &ds){
        if(i>=nums.size())
        {
            ans.push_back(ds);
            return;
        }
        //include
        ds.push_back(nums[i]);
        helper(i+1,nums,ans,ds);
        //not 
        ds.pop_back();
        helper(i+1,nums,ans,ds);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(0,nums,ans,ds);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};