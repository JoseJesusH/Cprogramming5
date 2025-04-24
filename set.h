#ifndef INT_SET_H
#define INT_SET_H

typedef struct IntSet IntSet;

IntSet* create_set();
void destroy_set(IntSet* set);

int add_to_set(IntSet* set, int value);
IntSet* union_sets(const IntSet* set1, const IntSet* set2);
IntSet* intersection_sets(const IntSet* set1, const IntSet* set2);
int contains(const IntSet* set, int value);
void print_set(const IntSet* set);

#endif

