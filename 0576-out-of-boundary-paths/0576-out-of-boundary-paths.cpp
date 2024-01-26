class Solution {
public:
    //Approach 1
    
    // const int mod = 1e9 + 7;
    // bool outOfBounds(int m, int n, int r, int c) {
    // return r < 0 || r >= m || c < 0 || c >= n;
    // }
    // int findPaths(int m, int n, int maxMove, int r, int c) {
    // bool isOut = outOfBounds(m, n, r, c);
    // if(isOut || !maxMove) return isOut;          // reached out of grid or ran out of moves
    // // try all moves from the current cell and add up all paths taking the ball out of bounds
    // return (findPaths(m, n, maxMove-1, r + 1, c)  + 
    // findPaths(m, n, maxMove-1, r - 1, c)  +    
    // findPaths(m, n, maxMove-1, r, c + 1)  +    
    // findPaths(m, n, maxMove-1, r, c - 1)) % mod;
    // }
    
    //Approach 2
    
    // const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // int dp[50][50][51] = {[0 ... 49] = {[0 ... 49] = {[0 ... 50] = -1}}};  // initialize all        elements to -1 denoting not yet computed
    // public:    
    // bool outOfBounds(int m, int n, int r, int c) {
    // return r < 0 || r >= m || c < 0 || c >= n;
    // }
    // int findPaths(int m, int n, int maxMove, int r, int c) {        
    // bool isOut = outOfBounds(m, n, r, c);
    // 	if(isOut || !maxMove) return isOut;
    // if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];  // return if already computed result
    // dp[r][c][maxMove] = 0;   // elements of dp are initalized to -1, so set to 0 before exploring moves
    // for(int i = 0; i < 4; i++) 
    // dp[r][c][maxMove] = (dp[r][c][maxMove] + findPaths(m, n, maxMove-1, r + moves[i][0], c + moves[i][1])) % mod;
    // return dp[r][c][maxMove];
    // }
    
    //Approach 3
    
    // const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // int findPaths(int m, int n, int maxMove, int r, int c) {
    // auto outOfBounds = [&](int m, int n, int r, int c){return r < 0 || r >= m || c < 0 || c >= n;};
    // uint dp[51][51][51]{};
    // for(int M = 1; M <= maxMove; M++)            // iterate for all available moves
    // for(int i = 0; i < m; i++) 
    // for(int j = 0; j < n; j++) 
    // for(int k = 0; k < 4; k++)       // for each cell, try all 4 possible moves
    // if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M]++;
    // else dp[i][j][M] += dp[i + moves[k][0]][j + moves[k][1]][M-1] % mod;
    // return dp[r][c][maxMove] % mod;
    // }
    
    //Approach 4
    
    const int mod = 1e9 + 7, moves[4][2] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int findPaths(int m, int n, int maxMove, int r, int c) {
	    auto outOfBounds = [&](int m, int n, int r, int c){return r < 0 || r >= m || c < 0 || c >= n;};
	    uint dp[50][50][2]{};        
	    for(int M = 1; M <= maxMove; M++)
		    for(int i = 0; i < m; i++) 
			    for(int j = 0, k; j < n; j++) 
				    for(k = 0, dp[i][j][M & 1] = 0; k < 4; k++) 
					    if(outOfBounds(m, n, i + moves[k][0], j + moves[k][1])) dp[i][j][M & 1]++;
					    else dp[i][j][M & 1] += dp[i + moves[k][0]][j + moves[k][1]][(M-1) & 1] % mod;
	    return dp[r][c][maxMove & 1] % mod;
    }
};