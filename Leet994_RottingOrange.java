import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class Leet994_RottingOrange {
    public int orangesRotting(int[][] grid) {

        if(grid == null) return -1;

        int row = grid.length, col = grid[0].length;
        Queue<int[]> q = new ArrayDeque<>();
        int totalOrg = 0, rottenOrg = 0, min=0;

        //find the start orange
        for(int i = 0; i < row; i++){
            for(int j=0; j < col; j++){
                if(grid[i][j]==2){
                    q.add(new int[]{i,j});
                    rottenOrg++;
                    totalOrg++;
                }else if (grid[i][j]==1){
                    totalOrg++;
                }
            }
        }
        //Impossible case
        if (totalOrg != 0 && q.size() == 0) return -1;
        if (totalOrg == 0) return 0;

        //BFS
        while(!q.isEmpty()){
            q = BFS(q, grid);
            min++;
            rottenOrg += q.size();
        }

        if(totalOrg == rottenOrg) return min-1;
        else return -1;
    }

    public Queue<int[]> BFS(Queue<int[]> q, int[][] grid){
        Queue<int[]> newQ = new LinkedList<>();
        while(!q.isEmpty()){
            checkNeighbors(grid, q.poll(), newQ);
        }
        return newQ;
    }

    public void checkNeighbors(int[][] grid, int[] cell, Queue<int[]> newQ){
        int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int[] di:dir){
            int x = cell[0] + di[0], y=cell[1] + di[1];
            if(x>=0 && x<grid.length && y>=0 && y<grid[0].length && grid[x][y]==1){
                grid[x][y]=2;
                newQ.add(new int[]{x,y});
            }
        }
    }

}
