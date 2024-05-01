#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct Node {
    float data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node into a bucket
void insert(struct Node** bucket, float data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *bucket;

    if (*bucket == NULL) {
        *bucket = newNode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create an array of linked list buckets
    int numBuckets = 10; // Assuming numbers are in range 0-9
    struct Node* buckets[numBuckets];
    int i;
    for ( i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into buckets
    for ( i = 0; i < n; i++) {
        int index = (int)(arr[i] * numBuckets); // Assuming each bucket holds numbers in range 0-1
        insert(&buckets[index], arr[i]);
    }

    // Merge buckets
    int index = 0;
    for ( i = 0; i < numBuckets; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}