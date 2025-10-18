/*
 * @lc app=leetcode id=200 lang=java
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    public int numIslands(char[][] grid) {
        if(grid == null || grid.length ==0) {
            return 0;
        }
        int numberOfOIslands  =0;
        for(int i=0; i<grid.length;i++){

            for (int j=0; j< grid[i].length;j++) {
                if(grid[i][j] =='1'){
                    dfs(grid,i,j);
                    numberOfOIslands ++;
                }
            }
        }

        return numberOfOIslands;
        }


        public void dfs(char[][] grid, int i, int j){

            if(i < 0 || i>= grid.length || j <0 || j >= grid[i].length
            || grid[i][j] == '0') {
                return;
            }

grid[i][j] ='0';
            //let us dfs of all 4 directions


            dfs(grid,i-1,j);
            dfs(grid,i,j+1);
            dfs(grid,i+1,j);
            dfs(grid,i,j-1);


        }
    }
// @lc code=end

