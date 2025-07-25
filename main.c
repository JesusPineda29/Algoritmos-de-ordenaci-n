#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "solution.h"

int main() {
    // Array desordenado para probar todos los algoritmos
    int original[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int n = 11;
    int test_array[11];
    
    printf("\n");
    printf("Array original: ");
    print_array(original, n);
    printf("\n");
    
    // Copiar array original para cada algoritmo
    for (int i = 0; i < n; i++) {
        test_array[i] = original[i];
    }
    
    // Probar Bubble Sort
    printf("=== BUBBLE SORT ===\n");
    reset_counters();
    clock_t start = clock();
    bubble_sort(test_array, n);
    clock_t end = clock();
    printf("Array ordenado: ");
    print_array(test_array, n);
    printf("Comparaciones: %lld\n", get_comparisons());
    printf("Intercambios: %lld\n", get_swaps());
    printf("Tiempo: %.6f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Restaurar array original
    for (int i = 0; i < n; i++) {
        test_array[i] = original[i];
    }
    
    // Probar Selection Sort
    printf("=== SELECTION SORT ===\n");
    reset_counters();
    start = clock();
    selection_sort(test_array, n);
    end = clock();
    printf("Array ordenado: ");
    print_array(test_array, n);
    printf("Comparaciones: %lld\n", get_comparisons());
    printf("Intercambios: %lld\n", get_swaps());
    printf("Tiempo: %.6f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Restaurar array original
    for (int i = 0; i < n; i++) {
        test_array[i] = original[i];
    }
    
    // Probar Insertion Sort
    printf("=== INSERTION SORT ===\n");
    reset_counters();
    start = clock();
    insertion_sort(test_array, n);
    end = clock();
    printf("Array ordenado: ");
    print_array(test_array, n);
    printf("Comparaciones: %lld\n", get_comparisons());
    printf("Intercambios: %lld\n", get_swaps());
    printf("Tiempo: %.6f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Restaurar array original
    for (int i = 0; i < n; i++) {
        test_array[i] = original[i];
    }
    
    // Probar Merge Sort
    printf("=== MERGE SORT ===\n");
    reset_counters();
    start = clock();
    merge_sort(test_array, n);
    end = clock();
    printf("Array ordenado: ");
    print_array(test_array, n);
    printf("Comparaciones: %lld\n", get_comparisons());
    printf("Intercambios: %lld\n", get_swaps());
    printf("Tiempo: %.6f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    // Restaurar array original
    for (int i = 0; i < n; i++) {
        test_array[i] = original[i];
    }
    
    // Probar Quick Sort
    printf("=== QUICK SORT ===\n");
    reset_counters();
    start = clock();
    quick_sort(test_array, n);
    end = clock();
    printf("Array ordenado: ");
    print_array(test_array, n);
    printf("Comparaciones: %lld\n", get_comparisons());
    printf("Intercambios: %lld\n", get_swaps());
    printf("Tiempo: %.6f segundos\n\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    return 0;
}