#include <stdio.h>
#include <stdlib.h>

// Hashmap node structure
typedef struct Node {
    long long sum;
    int freq;
    struct Node* next;
} Node;

#define SIZE 100003  // large prime for hashing

// Hash function
int hash(long long sum) {
    return (sum % SIZE + SIZE) % SIZE;
}

// Insert or update frequency of prefix sum
void insert(Node* table[], long long sum, int* count) {
    int idx = hash(sum);
    Node* curr = table[idx];
    
    while (curr) {
        if (curr->sum == sum) {
            *count += curr->freq;   // add frequency to count
            curr->freq += 1;        // update frequency
            return;
        }
        curr = curr->next;
    }
    
    // If not found, create new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->freq = 1;
    newNode->next = table[idx];
    table[idx] = newNode;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Node* table[SIZE] = {NULL};  // initialize hashmap
    long long prefix_sum = 0;
    int count = 0;
    
    // Insert initial prefix sum = 0
    insert(table, 0, &count);
    
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        insert(table, prefix_sum, &count);
    }
    
    printf("%d\n", count);
    return 0;
}
