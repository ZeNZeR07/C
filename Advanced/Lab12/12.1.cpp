#include <stdio.h>
#include <stdlib.h>

int findMax( int value1, int value2 ) ;
void KnapsackDP( int weights[], int values[], int itemCount, int capacity ) ;

int main() {
    int values[] = { 1, 6, 18, 22, 28 } ;
    int weights[] = { 1, 2, 5, 6, 7 } ;
    int capacity = 11 ;
    int itemCount = 5 ;

    KnapsackDP( weights, values, itemCount, capacity ) ;

    return 0 ;
}

int findMax( int value1, int value2 ) {
    if ( value1 > value2 ) {
        return value1 ;
    }
    return value2 ;
}

void KnapsackDP( int weights[], int values[], int itemCount, int capacity ) {
    int i, w ;
    int **table = ( int ** )malloc( ( itemCount + 1 ) * sizeof( int * ) ) ;
    
    for ( i = 0 ; i <= itemCount ; i++ ) {
        table[i] = ( int * )malloc( ( capacity + 1 ) * sizeof( int ) ) ;
    }

    for ( i = 0 ; i <= itemCount ; i++ ) {
        for ( w = 0 ; w <= capacity ; w++ ) {
            if ( i == 0 || w == 0 ) {
                table[i][w] = 0 ;
            }
            else if ( weights[i - 1] <= w ) {
                table[i][w] = findMax( values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w] ) ;
            }
            else {
                table[i][w] = table[i - 1][w] ;
            }
        }
    }

    printf( "%d", table[itemCount][capacity] ) ;

    for ( i = 0 ; i <= itemCount ; i++ ) {
        free( table[i] ) ;
    }
    free( table ) ;
}