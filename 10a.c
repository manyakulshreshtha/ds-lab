#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1  
void insert(int HT[], int m, int key) {
    int index = key % m;   
    int start = index;  
    while (HT[index] != EMPTY) {
        index = (index + 1) % m;
        if (index == start) {
            printf("Hash table is full, cannot insert key %d\n", key);
            return;
        }
    }
    HT[index] = key;
    printf("Inserted key %d at index %d\n", key, index);
}

int search(int HT[], int m, int key) {
    int index = key % m;
    int start = index;

    while (HT[index] != EMPTY) {
        if (HT[index] == key) {
            return index; 
        }
        index = (index + 1) % m;
        if (index == start) break; 
    }
    return -1; 
}
int main() {
    int m, N, i, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    int HT[m];
    for (i = 0; i < m; i++) HT[i] = EMPTY;

    printf("Enter number of employee records (N): ");
    scanf("%d", &N);

    printf("Enter %d employee keys (4-digit integers):\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &key);
        insert(HT, m, key);
    }

    printf("\nHash Table:\n");
    for (i = 0; i < m; i++) {
        if (HT[i] == EMPTY)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, HT[i]);
    }
    printf("\nEnter a key to search: ");
    scanf("%d", &key);
    int pos = search(HT, m, key);
    if (pos != -1)
        printf("Key %d found at index %d\n", key, pos);
    else
        printf("Key %d not found in hash table\n", key);

    return 0;
}