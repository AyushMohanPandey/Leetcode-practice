// class Solution {
// public:
//     int tribonacci(int n) {
//         if(n==0)
//             return 0;
//         if(n==1 || n==2)
//             return 1;
//         return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
//     }
// };


class Solution {
public:
    int dpSolve(int n, vector<int> &dp)
    {
        if(n==0)
             return 0;
        if(n==1 || n==2)
             return 1;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = dpSolve(n-1, dp)+dpSolve(n-2, dp)+dpSolve(n-3, dp);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return dpSolve(n, dp);
    }
};