import java.util.*;

class P36 {
    // @lc app=leetcode id=36 lang=java
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

