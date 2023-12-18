// ****** Recursion (Gets TLE) ********* TC = O(2^N), SC = O(N)
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==0 || n==1)
//             return 1;
//         return climbStairs(n-1)+climbStairs(n-2);
//     }
// };

// ******* Memoization **********         TC = O(N), SC = O(N)+O(N)
// class Solution {
// public:
//     int dpSolve(int n, vector<int> &dp)
//     {
//         if(n==0 || n==1)
//             return 1;
//         if(dp[n] != -1)
//             return dp[n];
//         dp[n] = dpSolve(n-1,dp) + dpSolve(n-2,dp);
//         return dp[n];
//     }
//     int climbStairs(int n) {
//         vector<int> dp(n+1,-1);
//         return dpSolve(n,dp);
//     }
// };

// ******* Tabulation **********         TC = O(N), SC = O(N)+O(N)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)
            return 1;
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};