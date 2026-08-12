void dfs(char** board, int m, int n, int r, int c) {
    // Base conditions: boundary check or check if cell is not 'O'
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
        return;
    }

    // Mark the escape-path cell with a temporary character
    board[r][c] = 'E';

    // Explore 4 directional neighbors
    dfs(board, m, n, r + 1, c);
    dfs(board, m, n, r - 1, c);
    dfs(board, m, n, r, c + 1);
    dfs(board, m, n, r, c - 1);
}

void solve(char** board, int boardSize, int* boardColSize) {
    if (boardSize == 0 || boardColSize[0] == 0) {
        return;
    }

    int m = boardSize;
    int n = boardColSize[0];

    // Step 1: Scan borders and run DFS on edge 'O' instances
    for (int i = 0; i < m; i++) {
        // Left border
        if (board[i][0] == 'O') dfs(board, m, n, i, 0);
        // Right border
        if (board[i][n - 1] == 'O') dfs(board, m, n, i, n - 1);
    }
    
    for (int j = 0; j < n; j++) {
        // Top border
        if (board[0][j] == 'O') dfs(board, m, n, 0, j);
        // Bottom border
        if (board[m - 1][j] == 'O') dfs(board, m, n, m - 1, j);
    }

    // Step 2: Post-process the entire grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X'; // Captured!
            } else if (board[i][j] == 'E') {
                board[i][j] = 'O'; // Safe, change back
            }
        }
    }
}
