import java.util.LinkedList;
import java.util.Queue;

public class Leet529_Minesweeper_BFS {
    public char[][] updateBoard(char[][] board, int[] click) {
        int x = click[0], y = click[1];

        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }

        int m = board.length, n= board[0].length;
        int[][] visited = new int[m][n];

        //BFS
        int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{x,y});
        visited[x][y] = 1;


        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int curX = cur[0], curY = cur[1];

            int checkMines = decision(board, curX, curY, dir);
            if(checkMines>0){
                board[curX][curY] =(char) (checkMines+'0');
            } else {
                board[curX][curY] = 'B';
                // Add neighbors when there is no mines nearby
                for(int[] d : dir) {
                    int newX = curX + d[0];
                    int newY = curY + d[1];
                    if(isValid(newX, newY, m, n) && (board[newX][newY] == 'E') && visited[newX][newY] == 0) {
                        q.add(new int[]{newX,newY});
                        visited[newX][newY] = 1;
                    }
                }
            }

        }
        return board;
    }

    private int decision(char[][] board, int x, int y, int[][] dir) {
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
