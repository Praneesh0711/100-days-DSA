#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            temp1 = temp1->next;
    } else {
        for (int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    scanf("%d", &m);
    int secondValues[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &secondValues[i]);

    for (int i = 0; i < m; i++)
        append(&head2, secondValues[i]);

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                temp2->next = temp1->next;
                temp2->data = temp1->data;
                break;
            }
            temp2 = temp2->next;
        }
        if (temp2 != NULL) break;
        temp1 = temp1->next;
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("%d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}
