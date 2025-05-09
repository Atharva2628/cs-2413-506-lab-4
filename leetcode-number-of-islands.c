void dfs(int i, int j, char** grid, int rows, int cols) {
    //see if the value is outside grid ot if its not land
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
        return;
    }

    
    //after checking make it marked as 0 being visited
    grid[i][j] = '0';
    //do all directions one by one
    dfs(i - 1, j, grid, rows, cols); //+y
    dfs(i + 1, j, grid, rows, cols); //-y
    dfs(i, j - 1, grid, rows, cols); //-x
    dfs(i, j + 1, grid, rows, cols); //+x
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;         
    int cols = *gridColSize;   
    int count = 0;//to count no of islands in there
    
    //loop all
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') { //land
                count++;
                dfs(i, j, grid, rows, cols);//set the full island as marked
            }
        }
    }
    return count;
}