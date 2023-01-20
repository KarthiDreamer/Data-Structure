#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the set
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node and add it to the set
void addNode(struct Node **head, int data) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If the set is empty, add the new node to the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Find the correct position to add the new node
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL && current->data < data) {
        prev = current;
        current = current->next;
    }

    // Add the new node to the set
    if (prev == NULL) {
        newNode->next = current;
        *head = newNode;
    }
    else {
        newNode->next = current;
        prev->next = newNode;
    }
}

// Function to check if a node with the given data exists in the set
int findNode(struct Node *head, int data) {
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to perform union on two sets
struct Node *setUnion(struct Node *set1, struct Node *set2) {
    struct Node *result = NULL;

    struct Node *current = set1;
    while (current != NULL) {
        addNode(&result, current->data);
        current = current->next;
    }

    current = set2;
    while (current != NULL) {
        if (!findNode(result, current->data)) {
            addNode(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

int main() {
    struct Node *set1 = NULL;
    struct Node *set2 = NULL;

    int data;
    printf("Enter elements for set1 (end with -1): \n");
    scanf("%d", &data);
    while (data != -1) {
        addNode(&set1, data);
        scanf("%d", &data);
    }

    printf("Enter elements for set2 (end with -1): \n");
    scanf("%d", &data);
    while (data != -1) {
        addNode(&set2, data);
        scanf("%d", &data);
    }

    struct Node *result = setUnion(set1, set2);

    printf("Union of the sets: ");
    struct Node *current = result;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
