#include <stdio.h>
#include <stdbool.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

// Binary Search (requires the array to be sorted)
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) {
            return mid;  // Return the index if the key is found
        }
        
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Return -1 if the key is not found
}

// Hash Table-based Search
#define TABLE_SIZE 1000

typedef struct {
    int key;
    int value;
} Entry;

Entry hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insertIntoHashTable(int key, int value) {
    int index = hashFunction(key);
    hashTable[index].key = key;
    hashTable[index].value = value;
}

int searchInHashTable(int key) {
    int index = hashFunction(key);
    if (hashTable[index].key == key) {
        return hashTable[index].value;
    } else {
        return -1; // Return -1 if the key is not found in the hash table
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int linearResult = linearSearch(arr, n, 30);
    printf("Linear Search Result: %d\n", linearResult);

    int binaryResult = binarySearch(arr, n, 30);
    printf("Binary Search Result: %d\n", binaryResult);

    insertIntoHashTable(1, 100);
    insertIntoHashTable(2, 200);

    int hashResult = searchInHashTable(2);
    printf("Hash Table Search Result: %d\n", hashResult);

    return 0;
}
