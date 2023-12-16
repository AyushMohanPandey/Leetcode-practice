class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, char ch)
    {
        for(int k=0; k<board.size(); k++)
        {
            if(board[i][k] == ch) 
                return false;
            if(board[k][j] == ch) 
                return false;
            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == ch)
                return false;   
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<board.size();i++){
           for(int j=0;j<board[0].size();j++){
               if(board[i][j] != '.')
               {
                   char ch = board[i][j];
                   board[i][j] = '.';
                   if(isValid(board, i, j, ch) == 0)
                       return false;
                   board[i][j] = ch;
               }
           }
       }
        return true;
    }
};