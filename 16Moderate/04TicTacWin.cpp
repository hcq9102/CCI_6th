

#include <iostream>
#include <vector>

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // 检查行
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // 检查列
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }

    // 检查主对角线
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    // 检查副对角线
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isWinner(const std::vector<std::vector<char>>& board, char player) {
    return checkWin(board, player);
}

int main() {
    // 示例井字游戏板
    std::vector<std::vector<char>> board = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'X', 'O', 'X'}
    };

    char player = 'X'; // 要检查的玩家
    if (isWinner(board, player)) {
        std::cout << "Player " << player << " wins!" << std::endl;
    } else {
        std::cout << "Player " << player << " does not win." << std::endl;
    }

    return 0;
}
/*
算法步骤
检查行：遍历每一行，检查是否有三个相同的符号。
检查列：遍历每一列，检查是否有三个相同的符号。
检查对角线：检查两条对角线，确认是否有三个相同的符号
*/
