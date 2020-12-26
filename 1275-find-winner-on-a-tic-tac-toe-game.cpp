class Solution {
  public:
    std::string tictactoe(const std::vector<std::vector<int>>& moves) {
      std::vector<std::string> grid(3, std::string(3, ' '));
      bool x_move = true;
      for (const auto& move : moves) {
        int row = move[0], column = move[1];
        if (x_move) {
          grid[row][column] = 'X';
        } else {  // O's move
          grid[row][column] = 'O';
        }
        x_move = !x_move;
      }
      std::unordered_map<char, std::string> char_to_player = {{'X', "A"}, {'O', "B"}};
      for (auto [ch, player] : char_to_player) {
        for (int row = 0; row < 3; ++row) {
          if (grid[row][0] == ch &&
              grid[row][1] == ch &&
              grid[row][2] == ch) {
            return player;
          }
        }
        for (int column = 0; column < 3; ++column) {
          if (grid[0][column] == ch &&
              grid[1][column] == ch &&
              grid[2][column] == ch) {
            return player;
          }
        }
        if (grid[0][0] == ch &&
            grid[1][1] == ch &&
            grid[2][2] == ch) {
          return player;
        }
        if (grid[0][2] == ch &&
            grid[1][1] == ch &&
            grid[2][0] == ch) {
          return player;
        }
      }
      if (moves.size() == 9) {
        return "Draw";
      } else {
        return "Pending";
      }
    }
};
