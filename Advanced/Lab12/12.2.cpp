#include <stdio.h>
#include <stdlib.h>

int findMax( int firstValue, int secondValue ) ;
void KnapsackDP( int itemWeights[], int itemValues[], int itemCount, int capacity ) ;

int main() {
    int itemValues[] = { 1, 6, 18, 22, 28 } ;
    int itemWeights[] = { 1, 2, 5, 6, 7 } ;
    int capacity = 11 ;
    int itemCount = 5 ;

    KnapsackDP( itemWeights, itemValues, itemCount, capacity ) ;

    return 0 ;
}

int findMax( int firstValue, int secondValue ) {
    if ( firstValue > secondValue ) {
        return firstValue ;
    }
    return secondValue ;
}

void KnapsackDP( int itemWeights[], int itemValues[], int itemCount, int capacity ) {
    int i, w ;
    int **dpTable = ( int ** )malloc( ( itemCount + 1 ) * sizeof( int * ) ) ;
    
    for ( i = 0 ; i <= itemCount ; i++ ) {
        dpTable[i] = ( int * )malloc( ( capacity + 1 ) * sizeof( int ) ) ;
    }

    for ( i = 0 ; i <= itemCount ; i++ ) {
        for ( w = 0 ; w <= capacity ; w++ ) {
            if ( i == 0 || w == 0 ) {
                dpTable[i][w] = 0 ;
            }
            else if ( itemWeights[i - 1] <= w ) {
                dpTable[i][w] = findMax( itemValues[i - 1] + dpTable[i - 1][w - itemWeights[i - 1]], dpTable[i - 1][w] ) ;
            }
            else {
                dpTable[i][w] = dpTable[i - 1][w] ;
            }
        }
    }

    printf( "%d", dpTable[itemCount][capacity] ) ;

    for ( i = 0 ; i <= itemCount ; i++ ) {
        free( dpTable[i] ) ;
    }
    free( dpTable ) ;
}