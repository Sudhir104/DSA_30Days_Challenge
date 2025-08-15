class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();       // Total number of rows
        int col = matrix[0].size();    // Total number of columns
        bool rowZero = false, colZero = false; // Flags for first row and first column

        // Check if first row has any zero
        for(int j = 0; j < col; j++)
            if(matrix[0][j] == 0) rowZero = true;

        // Check if first column has any zero
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0) colZero = true;

        // Use first row and first column as markers
        // Mark the row and column if any element is zero
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // Mark corresponding row
                    matrix[0][j] = 0; // Mark corresponding column
                }
            }
        }

        // Update the matrix using the markers
        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0; // Set element to zero if row/col is marked
            }
        }

        // Update first row if needed
        if(rowZero)
            for(int j = 0; j < col; j++) matrix[0][j] = 0;

        // Update first column if needed
        if(colZero)
            for(int i = 0; i < row; i++) matrix[i][0] = 0;
    }
};
