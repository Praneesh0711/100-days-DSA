#include <stdio.h>

int main() {
    int n, k;
    
    // Read size of array
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Read number of rotations
    scanf("%d", &k);
    
    // Normalize k (in case k > n)
    k = k % n;
    
    // Print rotated array
    for (int i = 0; i < n; i++) {
        int newIndex = (i - k + n) % n;  // shift right by k
        printf("%d ", arr[newIndex]);
    }
    
    return 0;
}
