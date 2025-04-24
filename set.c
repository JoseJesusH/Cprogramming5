#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct IntSet {
    int* data;
    int size;
    int capacity;
};

static int index_of(const IntSet* set, int value) {
    for (int i = 0; i < set->size; i++)
        if (set->data[i] == value) return i;
    return -1;
}

IntSet* create_set() {
    // Allocate memory for the set and initialize size
    IntSet* set = malloc(sizeof(IntSet));
    set->size = 0;
    set->capacity = 10;
    set->data = malloc(set->capacity * sizeof(int));
    return set;
}

void destroy_set(IntSet* set) {
  // Free memory after we're done
  free(set->data);
  free(set);
}

int add_to_set(IntSet* set, int value) {
    if (contains(set, value)) return 0;
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = realloc(set->data, set->capacity * sizeof(int));
    }
    set->data[set->size++] = value;
    return 1;
}

int contains(const IntSet* set, int value) {
    return index_of(set, value) != -1;
}

IntSet* union_sets(const IntSet* set1, const IntSet* set2) {
   // Create result set and add all elements of set1
   IntSet* result = create_set();
    for (int i = 0; i < set1->size; i++) add_to_set(result, set1->data[i]);
    // Add elements from b if they're not already present
    for (int i = 0; i < set2->size; i++) add_to_set(result, set2->data[i]);
    return result;
}

IntSet* intersection_sets(const IntSet* set1, const IntSet* set2) {
    IntSet* result = create_set();
    // Only add elements that exist in both sets
    for (int i = 0; i < set1->size; i++)
        if (contains(set2, set1->data[i])) add_to_set(result, set1->data[i]);
    return result;
}

void print_set(const IntSet* set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->data[i]);
    }
    printf("}\n");
}

