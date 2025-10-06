// Optimized implementation of Bubble sort with multiple data types and sort orders
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Enumeration pour définir l'ordre de tri
typedef enum {
    ASCENDING,  // Croissant
    DESCENDING  // Décroissant
} SortOrder;

// Enumeration pour définir le type de tri
typedef enum {
    INT_SORT,
    STRING_SORT,
    ALPHANUMERIC_SORT
} SortType;

// ============ FONCTIONS DE SWAP ============

void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// ============ FONCTIONS DE COMPARAISON ============

// Comparaison d'entiers
int compareInt(int a, int b, SortOrder order) {
    if (order == ASCENDING) {
        return a > b;
    } else {
        return a < b;
    }
}

// Comparaison de chaînes de caractères
int compareString(const char* a, const char* b, SortOrder order) {
    int result = strcmp(a, b);
    if (order == ASCENDING) {
        return result > 0;
    } else {
        return result < 0;
    }
}

// Fonction pour extraire un nombre depuis une chaîne
int extractNumber(const char* str, int* pos) {
    int num = 0;
    while (str[*pos] && isdigit(str[*pos])) {
        num = num * 10 + (str[*pos] - '0');
        (*pos)++;
    }
    return num;
}

// Comparaison alphanumérique (traite les nombres dans les chaînes comme des nombres)
int compareAlphanumeric(const char* a, const char* b, SortOrder order) {
    int i = 0, j = 0;
    
    while (a[i] && b[j]) {
        // Si les deux caractères sont des chiffres
        if (isdigit(a[i]) && isdigit(b[j])) {
            int numA = extractNumber(a, &i);
            int numB = extractNumber(b, &j);
            
            if (numA != numB) {
                if (order == ASCENDING) {
                    return numA > numB;
                } else {
                    return numA < numB;
                }
            }
        }
        // Sinon, comparaison caractère par caractère
        else {
            if (a[i] != b[j]) {
                if (order == ASCENDING) {
                    return a[i] > b[j];
                } else {
                    return a[i] < b[j];
                }
            }
            i++;
            j++;
        }
    }
    
    // Gérer les chaînes de longueurs différentes
    if (order == ASCENDING) {
        return strlen(a) > strlen(b);
    } else {
        return strlen(a) < strlen(b);
    }
}

// ============ FONCTIONS DE TRI ============

// Tri à bulles pour les entiers
void bubbleSortInt(int arr[], int n, SortOrder order) {
    int i, j;
    bool swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (compareInt(arr[j], arr[j + 1], order)) {
                swapInt(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Tri à bulles pour les chaînes de caractères
void bubbleSortString(char* arr[], int n, SortOrder order) {
    int i, j;
    bool swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (compareString(arr[j], arr[j + 1], order)) {
                swapString(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Tri à bulles alphanumérique
void bubbleSortAlphanumeric(char* arr[], int n, SortOrder order) {
    int i, j;
    bool swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (compareAlphanumeric(arr[j], arr[j + 1], order)) {
                swapString(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ============ FONCTIONS D'AFFICHAGE ============

void printIntArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printStringArray(char* arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("\"%s\" ", arr[i]);
    }
    printf("\n");
}

// ============ FONCTION PRINCIPALE ============

int main() {
    printf("=== Tests de tri avec différents types et ordres ===\n\n");
    
    // Test 1: Tri d'entiers
    printf("1. Tri d'entiers:\n");
    int intArr[] = {64, 34, 25, 12, 22, 11, 90};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    printf("Tableau original: ");
    printIntArray(intArr, intSize);
    
    // Tri croissant
    int intArrAsc[7];
    memcpy(intArrAsc, intArr, sizeof(intArr));
    bubbleSortInt(intArrAsc, intSize, ASCENDING);
    printf("Tri croissant: ");
    printIntArray(intArrAsc, intSize);
    
    // Tri décroissant
    int intArrDesc[7];
    memcpy(intArrDesc, intArr, sizeof(intArr));
    bubbleSortInt(intArrDesc, intSize, DESCENDING);
    printf("Tri décroissant: ");
    printIntArray(intArrDesc, intSize);
    
    printf("\n");
    
    // Test 2: Tri de chaînes de caractères
    printf("2. Tri de chaînes de caractères:\n");
    char* stringArr[] = {"banana", "apple", "cherry", "date", "elderberry"};
    int stringSize = 5;
    
    printf("Tableau original: ");
    printStringArray(stringArr, stringSize);
    
    // Créer des copies pour les tests
    char* stringArrAsc[] = {"banana", "apple", "cherry", "date", "elderberry"};
    char* stringArrDesc[] = {"banana", "apple", "cherry", "date", "elderberry"};
    
    bubbleSortString(stringArrAsc, stringSize, ASCENDING);
    printf("Tri croissant: ");
    printStringArray(stringArrAsc, stringSize);
    
    bubbleSortString(stringArrDesc, stringSize, DESCENDING);
    printf("Tri décroissant: ");
    printStringArray(stringArrDesc, stringSize);
    
    printf("\n");
    
    // Test 3: Tri alphanumérique
    printf("3. Tri alphanumérique:\n");
    char* alphaArr[] = {"item2", "item10", "item1", "item20", "item3"};
    int alphaSize = 5;
    
    printf("Tableau original: ");
    printStringArray(alphaArr, alphaSize);
    
    // Créer des copies pour les tests
    char* alphaArrAsc[] = {"item2", "item10", "item1", "item20", "item3"};
    char* alphaArrDesc[] = {"item2", "item10", "item1", "item20", "item3"};
    
    bubbleSortAlphanumeric(alphaArrAsc, alphaSize, ASCENDING);
    printf("Tri alphanumérique croissant: ");
    printStringArray(alphaArrAsc, alphaSize);
    
    bubbleSortAlphanumeric(alphaArrDesc, alphaSize, DESCENDING);
    printf("Tri alphanumérique décroissant: ");
    printStringArray(alphaArrDesc, alphaSize);
    
    return 0;
}