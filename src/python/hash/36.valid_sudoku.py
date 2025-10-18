class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows= [set() for _ in range(9)]
        cols= [set() for _ in range(9)]
        grid= [[set() for _ in range(3)] for _ in range(3)]

        for row in range(9):
            for col in range(9):
                cur_item = board[row][col]
                if cur_item == "." :
                    continue
                else:
                    if cur_item in rows[row]:
                        return False
                    if cur_item in cols[col]:
                        return False
                    if cur_item in grid[row//3][col//3]:
                        return False

                    rows[row].add(cur_item)
                    cols[col].add(cur_item)
                    grid[row//3][col//3].add(cur_item) 
        return True                           