class Solution {
  public:
    void gameOfLife(vector<vector<int>>& board) {
      int rows = board.size(), cols = board[0].size();
      vector<vector<int>> new_board(rows, vector<int>(cols));
      for (int row = 0; row < rows; ++row)
        for (int rd = -1; rd <= 1; ++rd)
          if (0 <= row + rd && row + rd < rows)
            for (int col = 0; col < cols; ++col)
              for (int cd = -1; cd <= 1; ++cd)
                if (0 <= col + cd && col + cd < cols && (rd != 0 || cd != 0))
                  new_board[row + rd][col + cd] += board[row][col];
      for (int row = 0; row < rows; ++row)
        for (int col = 0; col < cols; ++col)
          if (new_board[row][col] < 2 || new_board[row][col] > 3)
            board[row][col] = 0;
          else if (board[row][col] || new_board[row][col] == 3)
            board[row][col] = 1;
    }
};
