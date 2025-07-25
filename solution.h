#ifndef SOLUTION_H
#define SOLUTION_H

// Declaraciones de funciones de ordenación
void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int n);
void quick_sort(int arr[], int n);

// Funciones auxiliares para análisis empírico
void reset_counters(void);
long long get_comparisons(void);
long long get_swaps(void);

// Funciones de utilidad
void print_array(int arr[], int n);
int is_sorted(int arr[], int n);

#endif // SOLUTION_H