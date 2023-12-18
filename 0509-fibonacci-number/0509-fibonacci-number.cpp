// ******* Recurion approach ********

// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1)
//             return n;
//         return fib(n-1)+fib(n-2);
//     }
// };

// ******* Memoization approach *******

class Solution {
    public:
    int dpSolve(int n, vector<int> &dp)
    {
        if(n<=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = dpSolve(n-1, dp) + dpSolve(n-2, dp);
        return dp[n];
    }
    
    int fib(int n) {
        vector<int> dp(n+1,-1);
        // dpSolve(n, dp);
        return dpSolve(n, dp);
    }
};