#include <stdio.h>

int main() {
    int n, pos;
    scanf("%d", &n);

    int arr[100]; // assuming max size 100
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

  
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    
    for (int i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i != n - 2) printf(" ");
    }
    printf("\n");

    return 0;
}
