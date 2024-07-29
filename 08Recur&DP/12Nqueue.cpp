//https://godbolt.org/z/zsvKzr441

#include<bits/stdc++.h>

using namespace std;

// valid place(row, col) to put Queen: left upper diag & right upper diag has no Queen
 //                            before  row, col has no Queue 


bool isValid(vector<vector<char>>& board, int row, int col){
    // row valid
    for(int i = 0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    // valid left upper diag
    for(int i = row-1, j = col-1; i>=0&j>=0; i--,j--){
        if(board[i][j]== 'Q') return false;
    }

    // valid right upper diag
    for(int i = row-1, j = col+1; i>=0&j>=0; i--,j++){
        if(board[i][j]== 'Q') return false;
    }

    return true;
    
}

vector<string> transToBoard(const vector<vector<char>>& board) {
        vector<string> result;
        for (const auto& row : board) {
            result.push_back(string(row.begin(), row.end()));
        }
        return result;
}

void dfs(vector<vector<string>>& res, vector<vector<char>>& board, int row){
    if(row == board.size()){
        res.push_back(transToBoard(board));
        return;
    }
    /*
         * 路径：board中小于row的那些行都已经成功放置了皇后
         * 可选择列表: 第row行的所有列都是放置Q的选择
         * 结束条件: row超过board的最后一行
    */
    for(int col = 0; col<board[0].size(); col++){
        if(isValid(board, row, col)){
            board[row][col] = 'Q';
            dfs(res, board,row+1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    dfs(res, board, 0);
    return res;
}



int main() {
    int n = 8;
    vector<vector<string>> results = solveNQueens(n);
    
    cout << "N "<<n << " Queens have " << results.size()<<" solutions"<<endl;

    for (const auto& solution : results) {
        for (const auto& line : solution) {
            cout << line << endl;
        }
        cout << endl;
    }
    
    return 0;
}
