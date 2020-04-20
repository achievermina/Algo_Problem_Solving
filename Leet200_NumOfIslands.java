public class Leet200_NumOfIslands {

    private int m, n;
    private int[][] visited;

    public int numIslands(char[][] grid) {
        int res = 0;
        m = grid.length;
        if (m < 1){
            return 0;
        }
        n = grid[0].length;
        if (n < 1){
            return grid[0][0] == 0? 0:1;
        }

        visited = new int[m][n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    if (visited[i][j] ==1) continue;
                    res++;
                    DFS(i, j , grid, visited);
                }

            }
        }
        return res;
    }

    //First try - > only checks right, down. However, we need to check left or up as well
    private void DFS(int i, int j, char[][] grid, int[][] visited){
        int[][] dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for (int[] d : dir) {
            int newx = i+d[0], newy = j+d[1];

            if( newx>=0 && newy>=0 && newx< grid.length && newy < grid[0].length && grid[newx][newy] == '1' && visited[newx][newy] == 0) {
                visited[newx][newy] =1;
                DFS(newx,newy,grid,visited);
            }
        }
    }

}
