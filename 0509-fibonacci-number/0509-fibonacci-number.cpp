// ******* Recurion approach ********       TC = O(2^N) , SC = O(N)

// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1)
//             return n;
//         return fib(n-1)+fib(n-2);
//     }
// };

// ******* Memoization approach *******     TC = O(N) , SC = O(N)+O(N)

// class Solution {
//     public:
//     int dpSolve(int n, vector<int> &dp)
//     {
//         if(n<=1)
//             return n;
//         if(dp[n] != -1)
//             return dp[n];
//         dp[n] = dpSolve(n-1, dp) + dpSolve(n-2, dp);
//         return dp[n];
//     }
    
//     int fib(int n) {
//         vector<int> dp(n+1,-1);
//         // dpSolve(n, dp);
//         return dpSolve(n, dp);
//     }
// };


// ******** Tabulation ********        TC = O(N) , SC = O(N)

// class Solution {
// public:
//     int fib(int n) {
//         if(n<=1)
//             return n;
//         vector<int> dp(n+1, -1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for(int i=2; i<=n; i++)
//         {
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };

//******** Space optimization *********  TC = O(N) , SC = O(1)
class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        int prev2 = 0;
        int prev = 1;
        for(int i=2; i<=n; i++)
        {
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};








