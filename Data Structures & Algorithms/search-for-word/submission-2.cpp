#include <ranges>
class Solution {
public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
  {
    std::vector<std::vector<int>> visited;
    visited.reserve(board.size());
    for (auto const &r: board) {
      visited.emplace_back(r.size(), 0);
    }
    for (auto const r: std::ranges::views::iota(0, static_cast<int>(board.size()))) {
      for (auto const c: std::ranges::views::iota(0, static_cast<int>(board[r].size())))
      {
        if (backtrace(board, visited, word, 0, r, c)) {
          return true;
        }
      }
    }
    return false;
  }

  bool backtrace(std::vector<std::vector<char>> const &board,
                 std::vector<std::vector<int>> &visited,
                 std::string_view const word,
                 int index,
                 int row,
                 int col)
  {
    if (index == word.size()) {
      return true;
    }
    if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size() ||
        visited[row][col] != 0 || board[row][col] != word[index])
    {
      return false;
    }
    visited[row][col]++;
    // down
    auto const res = backtrace(board, visited, word, index + 1, row + 1, col) ||
                     // up
                     backtrace(board, visited, word, index + 1, row - 1, col) ||
                     // right
                     backtrace(board, visited, word, index + 1, row, col + 1) ||
                     // left
                     backtrace(board, visited, word, index + 1, row, col - 1);
    visited[row][col]--;
    return res;
  }
};
