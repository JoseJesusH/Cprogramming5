// main_set.c
#include <stdio.h>
#include "set.h"

int main() {
    // Create two sets
    IntSet* setA = create_set();
    IntSet* setB = create_set();

    // Add elements to set A
    add_to_set(setA, 1);
    add_to_set(setA, 2);
    add_to_set(setA, 3);

    // Add elements to set B
    add_to_set(setB, 2);
    add_to_set(setB, 3);
    add_to_set(setB, 4);

    // Display the sets
    printf("Set A: ");
    print_set(setA);
    printf("Set B: ");
    print_set(setB);

    // Union and intersection
    IntSet* unionAB = union_sets(setA, setB);
    IntSet* interAB = intersection_sets(setA, setB);

    printf("Union: ");
    print_set(unionAB);

    printf("Intersection: ");
    print_set(interAB);

    // Cleanup
    destroy_set(setA);
    destroy_set(setB);
    destroy_set(unionAB);
    destroy_set(interAB);

    return 0;
}

