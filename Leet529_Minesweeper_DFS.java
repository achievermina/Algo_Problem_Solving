public class Leet529_Minesweeper_DFS {
    // Updated DFS
    int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int m,n;
    int[][] visited;
    public char[][] updateBoard(char[][] board, int[] click) {
        int x = click[0], y = click[1];

        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        m = board.length; n= board[0].length;
        visited = new int[m][n];


        visited[x][y] = 1;
        DFS(board, x, y);
        return board;
    }

    private void DFS(char[][] board, int curX, int curY) {
        int checkMines = decision(board, curX, curY);
        if(checkMines>0){
            board[curX][curY] =(char) (checkMines+'0');
        } else {
            board[curX][curY] = 'B';
            for(int[] d : dir) {
                int newX = curX + d[0];
                int newY = curY + d[1];
                if(isValid(newX, newY, board.length, board[0].length) && (board[newX][newY] == 'E') && visited[newX][newY] == 0) {
                    visited[newX][newY] = 1;
                    DFS(board, newX, newY);
                }
            }
        }
    }

    private int decision(char[][] board, int x, int y) {
        int mine = 0;
        for(int[] d : dir) {
            int newX = x + d[0];
            int newY = y + d[1];
            if(isValid(newX, newY, board.length, board[0].length) && board[newX][newY]=='M') {
                mine++;
            }
        }
        return mine;
    }

    private boolean isValid(int x, int y, int xMax, int yMax) {
        return x >=0 && x < xMax && y >=0 && y < yMax;
    }
}
