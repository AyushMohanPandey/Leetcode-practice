class Solution {
public:
    int dpSolve(vector<int> &cost, int n, vector<int> &dp)
    {
        if(n<=1)
            return cost[n];
        if(dp[n] != -1)
            return dp[n];
        dp[n] = cost[n]+ min(dpSolve(cost,n-1,dp), dpSolve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(dpSolve(cost,n-1,dp), dpSolve(cost,n-2,dp));
    }
};