public class Solution {
    HashSet<Tuple<int, int>> visited = 
    new HashSet<Tuple<int, int>>();
    public int NumIslands(char[][] grid) {
        int count = 0;
        for(int r = 0; r < grid.Length; r++)
        {
            for(int c = 0; c < grid[0].Length; c++)
            {
                if(explore(grid, r, c)){
                    count++;
                }
            }
        }
        return count;
    }
    bool explore(char[][] grid, int r, int c){
        bool rowInBounds = 0 <= r && r < grid.Length;
        bool colInBounds = 0 <= c && c < grid[0].Length;
        if(!rowInBounds || !colInBounds) 
        {
            return false;
        }
        Console.WriteLine("hi");

        if(grid[r][c] == '0') 
        {
            return false;

        }

        Tuple<int, int> tmp = new Tuple<int, int>(r, c);
        if(visited.Contains(tmp)) {
            return false;
        }
        visited.Add(tmp);

        explore(grid, r - 1, c);
        explore(grid, r + 1, c);
        explore(grid, r, c - 1);
        explore(grid, r, c + 1);

        return true;
    }
}
