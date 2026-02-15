#include <stdio.h>

int main() {
    int m, n;
    
    // Read the number of rows (m) and columns (n)
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];  // Declare a 2D array to store the matrix
    
    // Input the matrix elements row by row
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);  // Read each element
        }
    }
    
    int diag_sum = 0;  // Variable to store the sum of primary diagonal
    
    // Traverse only the primary diagonal (where row index == column index)
    // Use min(m, n) to avoid accessing out of bounds if matrix is not square
    int limit = (m < n) ? m : n;
    for (int i = 0; i < limit; i++) {
        diag_sum += matrix[i][i];  // Add the diagonal element to sum
    }
    
    // Print the final sum of primary diagonal elements
    printf("%d\n", diag_sum);
}
