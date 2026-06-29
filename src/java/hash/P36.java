package hash;
import common.*;
import java.util.*;

public class P36 {
/*
 * @lc app=leetcode id=36 lang=java
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to
 * be validated according to the following rules:
 *
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 *    without repetition.
 *
 * Note:
 * - A Sudoku board (partially filled) could be valid but is not necessarily
 *   solvable.
 * - Only the filled cells need to be validated according to the mentioned
 *   rules.
 *
 * Example 1:
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".","4","1","9",".",".","5"]]
 * Output: true
 *
 * Example 2:
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".","8",".",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 * Constraints:
 * - board.length == 9
 * - board[i].length == 9
 * - board[i][j] is a digit 1-9 or '.'.
 */
    // @lc code=start
    public class Solution {
    public boolean isValidSudoku(char[][] board) {

        if(board==null || board.length ==0 || board[0].length ==0)
            return false;

        List<Set<Character>> rows = new ArrayList<>();
        List<Set<Character>> cols = new ArrayList<>();

        List<List<Set<Character>>> gridLists = new ArrayList<>();

        for(int i=0; i< 9; i++){
           rows.add(new HashSet<>()) ;   
           cols.add(new HashSet<>());
        }

        for (int i =0; i<3;i++){
            List<Set<Character>>  list = new ArrayList<>();
            gridLists.add(list);
            
            for(int j =0; j <3; j++) {
                list.add(new HashSet<>()) ; 
            }

        }


        for(int i =0; i <9;i++) {
            for (int j =0; j <9; j++) {

                char elem = board[i][j];

                if(elem == '.') {
                    continue;
                }
           
                Set<Character> rowSet = rows.get(i);
                Set<Character> colsSet = cols.get(j);
                boolean newElem = rowSet.add(elem);
                if(!newElem) {
                
                    return false;
                }
                newElem = colsSet.add(elem);
                if(!newElem) {
                  
                    return false;
                }
                
                int gridRowIndex = i /3;
                int gridColIndex = j / 3;
                List<Set<Character>> list = gridLists.get(gridRowIndex);
                Set<Character> gridSet = list.get(gridColIndex);

                newElem =gridSet.add(elem);
                if(!newElem) {
                  
                    return false;
                }


            }
        }

        return true;
    }
    }
    // @lc code=end
}

