class Solution {
public:
    //Approach 1
    // int rec(vector<int>& nums,int i){
    //     if(i>=nums.size())return 0;
    //     return max(nums[i]+rec(nums,i+2),rec(nums,i+1));
    // }
    // int rob(vector<int>& nums) {
    //     return rec(nums,0);
    // }
    
    //Approach 2
    int rec(vector<int>& nums,int idx,vector<int>&dp){
       if(idx >= nums.size()) return 0;
       if(dp[idx] != -1) return dp[idx];
       return dp[idx] = max(rec(nums, idx+1, dp), nums[idx] + rec(nums, idx+2, dp));
     }
    int rob(vector<int>& nums) {
      vector<int>dp(nums.size()+1,-1);
      return rec(nums,0,dp);
    }
};