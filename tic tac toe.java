class Solution {
    public boolean validTicTacToe(String[] board) {
        int xCount = 0;
        int oCount = 0;

        // 1. Count X and O
        for (String row : board) {
            for (char c : row.toCharArray()) {
                if (c == 'X') xCount++;
                if (c == 'O') oCount++;
            }
        }

        // Rule: X starts first, so X count must be O count or O count + 1
        if (xCount != oCount && xCount != oCount + 1) return false;

        boolean xWins = isWin(board, 'X');
        boolean oWins = isWin(board, 'O');

        // 2. Check winning conditions
        if (xWins && oWins) return false; // Both can't win
        if (xWins && xCount != oCount + 1) return false; // X wins, must be X's turn end
        if (oWins && xCount != oCount) return false; // O wins, must be O's turn end

        return true;
    }

    private boolean isWin(String[] board, char p) {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i].charAt(0) == p && board[i].charAt(1) == p && board[i].charAt(2) == p) return true;
            if (board[0].charAt(i) == p && board[1].charAt(i) == p && board[2].charAt(i) == p) return true;
        }
        // Check diagonals
        if (board[0].charAt(0) == p && board[1].charAt(1) == p && board[2].charAt(2) == p) return true;
        if (board[0].charAt(2) == p && board[1].charAt(1) == p && board[2].charAt(0) == p) return true;
        
        return false;
    }
}
