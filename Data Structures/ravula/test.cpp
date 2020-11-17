#include <bits/stdc++.h>

using namespace std;


bool isValidBox(vector<string>& board, int row, int col)
{
    for (int i = col; i >= 0; --i)
        if (board.at(row).at(i) == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board.at(i).at(j) == 'Q')
            return false;

    for (int i = row, j = col; i < board.size() && j >= 0; ++i, --j)
        if (board.at(i).at(j) == 'Q')
            return false;

    return true;
}

void solveNQ(vector<vector<string>>& res, vector<string> board, int col)
{
    if (col == board.size()) {
        res.emplace_back(board);
        return;
    }

    for (int row = 0; row < board.size(); row++) {
        if (isValidBox(board, row, col)) {
            board.at(row).at(col) = 'Q';
            solveNQ(res, board, col + 1);
            board.at(row).at(col) = '_';
        }
    }
}

vector<vector<string> > solveNQueens(int A) {
    if (A == 2 || A == 3)
        return vector<vector<string>> ();

    vector<vector<string>> res;
    vector<string> board(A);
    for (int i = 0; i < A; ++i)
        board.at(i) = string(A, '_');

    solveNQ(res, board, 0);
    return res;
}

int main()
{
    vector<vector<string>> res;
    res = solveNQueens(20);
//    vector<string> ans = res.at(0);
//    for (string s: ans) {
//        for (char c: s)
//            cout << c << " ";
//        cout << "\n";
//    }
    cout << res.size();
    return 0;
}
