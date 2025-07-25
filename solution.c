#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

// Variables globales para contar operaciones (si es necesario para el análisis empírico)
long long comparisons = 0;
long long swaps = 0;

/**
 * Algoritmo de ordenación burbuja
 * Complejidad: O(n²) en el peor caso, O(n) en el mejor caso
 */
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Intercambio
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = 1;
            }
        }
        // Si no hubo intercambios, el array ya está ordenado
        if (swapped == 0) {
            break;
        }
    }
}

/**
 * Algoritmo de ordenación por selección
 * Complejidad: O(n²) en todos los casos
 */
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Intercambio si es necesario
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swaps++;
        }
    }
}

/**
 * Algoritmo de ordenación por inserción
 * Complejidad: O(n²) en el peor caso, O(n) en el mejor caso
 */
void insertion_sort(int arr[], int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // Mover elementos mayores que key una posición adelante
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
                swaps++;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

/**
 * Función auxiliar para merge_sort: mezcla dos subarrays ordenados
 */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Arrays temporales
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    
    // Copiar datos a los arrays temporales
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Mezclar los arrays temporales de vuelta en arr[left..right]
    i = 0; // Índice inicial del primer subarray
    j = 0; // Índice inicial del segundo subarray
    k = left; // Índice inicial del subarray mezclado
    
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        swaps++;
    }
    
    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }
    
    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
    
    free(L);
    free(R);
}

/**
 * Algoritmo de ordenación por mezcla (merge sort)
 * Complejidad: O(n log n) en todos los casos
 */
void merge_sort_recursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Ordenar primera y segunda mitad
        merge_sort_recursive(arr, left, mid);
        merge_sort_recursive(arr, mid + 1, right);
        
        // Mezclar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

void merge_sort(int arr[], int n) {
    merge_sort_recursive(arr, 0, n - 1);
}

/**
 * Función auxiliar para quick_sort: particiona el array
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Elegir el último elemento como pivote
    int i = (low - 1); // Índice del elemento más pequeño
    int temp;
    
    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot) {
            i++; // Incrementar índice del elemento más pequeño
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;
        }
    }
    
    // Colocar el pivote en su posición correcta
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    swaps++;
    
    return (i + 1);
}

/**
 * Algoritmo de ordenación rápida (quick sort)
 * Complejidad: O(n log n) promedio, O(n²) peor caso
 */
void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        // pi es el índice de partición
        int pi = partition(arr, low, high);
        
        // Ordenar elementos antes y después de la partición
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(int arr[], int n) {
    quick_sort_recursive(arr, 0, n - 1);
}

/**
 * Funciones auxiliares para análisis empírico
 */
void reset_counters(void) {
    comparisons = 0;
    swaps = 0;
}

long long get_comparisons(void) {
    return comparisons;
}

long long get_swaps(void) {
    return swaps;
}

/**
 * Función auxiliar para imprimir un array (útil para depuración)
 */
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Función para verificar si un array está ordenado
 */
int is_sorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0; // No está ordenado
        }
    }
    return 1; // Está ordenado
}