#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int key;
    int state;  // 0 = empty, 1 = occupied, 2 = deleted
} HashEntry;

size_t hashFunction(int key, size_t capacity) {
    uint32_t x = (uint32_t)key;

    x ^= x >> 16;
    x *= UINT32_C(0x7feb352d);
    x ^= x >> 15;
    x *= UINT32_C(0x846ca68b);
    x ^= x >> 16;

    return (size_t)x & (capacity - 1);
}

bool contains(HashEntry *table, size_t capacity, int key) {
    size_t index = hashFunction(key, capacity);

    for (size_t i = 0; i < capacity; i++) {
        if (table[index].state == 0)
            return false;

        if (table[index].state == 1 && table[index].key == key)
            return true;

        index = (index + 1) & (capacity - 1);
    }

    return false;
}

void insert(HashEntry *table, size_t capacity, int key) {
    size_t index = hashFunction(key, capacity);
    size_t deleted = capacity;

    for (size_t i = 0; i < capacity; i++) {
        if (table[index].state == 1 && table[index].key == key)
            return;

        if (table[index].state == 2 && deleted == capacity)
            deleted = index;

        if (table[index].state == 0) {
            if (deleted != capacity)
                index = deleted;

            table[index].key = key;
            table[index].state = 1;
            return;
        }

        index = (index + 1) & (capacity - 1);
    }

    if (deleted != capacity) {
        table[deleted].key = key;
        table[deleted].state = 1;
    }
}

void removeElement(HashEntry *table, size_t capacity, int key) {
    size_t index = hashFunction(key, capacity);

    for (size_t i = 0; i < capacity; i++) {
        if (table[index].state == 0)
            return;

        if (table[index].state == 1 && table[index].key == key) {
            table[index].state = 2;
            return;
        }

        index = (index + 1) & (capacity - 1);
    }
}

bool containsNearbyDuplicate(int nums[], int numsSize, int k) {
    if (k <= 0 || numsSize <= 0)
        return false;

    size_t limit = (size_t)numsSize;
    if ((size_t)k + 1 < limit)
        limit = (size_t)k + 1;

    size_t capacity = 1;
    while (capacity < limit * 2)
        capacity *= 2;

    HashEntry *window = calloc(capacity, sizeof(HashEntry));

    if (window == NULL)
        return false;

    for (int i = 0; i < numsSize; i++) {

        if (contains(window, capacity, nums[i])) {
            free(window);
            return true;
        }

        insert(window, capacity, nums[i]);

        if (i >= k) {
            removeElement(window, capacity, nums[i - k]);
        }
    }

    free(window);
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    bool result = containsNearbyDuplicate(nums, n, k);

    printf("%s\n", result ? "true" : "false");

    return 0;
}