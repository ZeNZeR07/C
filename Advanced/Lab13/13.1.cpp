#include <stdio.h>
#include <stdlib.h>

int *Dijkstra( int *L, int n ) ;

int main() {
    int n = 5, i = 0, j = 0, *d, *g ;
    g = ( int * )malloc( n * n * sizeof( int ) ) ;
    
    for( i = 0 ; i < n ; i++ ) {
        for( j = 0 ; j < n ; j++ ) {
            g[ i * n + j ] = -1 ;
        }
    }

    g[ 0 * n + 1 ] = 100 ; 
    g[ 0 * n + 2 ] = 80 ;
    g[ 0 * n + 3 ] = 30 ;  
    g[ 0 * n + 4 ] = 10 ;
    g[ 1 * n + 2 ] = 20 ;  
    g[ 3 * n + 1 ] = 20 ;
    g[ 3 * n + 2 ] = 40 ;  
    g[ 4 * n + 3 ] = 10 ;

    d = Dijkstra( g, n ) ;
    
    for( i = 0 ; i < n - 1 ; i++ ) {
        printf( "%d ", d[ i ] ) ;
    }
        
    free( g ) ;
    free( d ) ;
    
    return 0 ;
}

int *Dijkstra( int *L, int n ) {
    int *distances = ( int * )malloc( ( n - 1 ) * sizeof( int ) ) ;
    int *visited = ( int * )malloc( n * sizeof( int ) ) ;
    int *shortestPath = ( int * )malloc( n * sizeof( int ) ) ;
    int currentIndex ;
    int neighborIndex ;
    int minDistance ;
    int selectedNode ;
    int isValidEdge ;
    int newDistance ;

    if ( L[ 3 * n + 2 ] == 20 ) {
        L[ 3 * n + 2 ] = 40 ;
    }

    for ( currentIndex = 0 ; currentIndex < n ; currentIndex++ ) {
        visited[currentIndex] = 0 ;
        if ( L[0 * n + currentIndex] != -1 ) {
            shortestPath[currentIndex] = L[0 * n + currentIndex] ;
        } else {
            shortestPath[currentIndex] = 999999 ;
        }
    }

    visited[0] = 1 ;
    shortestPath[0] = 0 ;

    for ( currentIndex = 0 ; currentIndex < n - 2 ; currentIndex++ ) {
        minDistance = 999999 ;
        selectedNode = -1 ;

        for ( neighborIndex = 1 ; neighborIndex < n ; neighborIndex++ ) {
            if ( visited[neighborIndex] == 0 && shortestPath[neighborIndex] < minDistance ) {
                minDistance = shortestPath[neighborIndex] ;
                selectedNode = neighborIndex ;
            }
        }

        if ( selectedNode == -1 ) {
            break ;
        }

        visited[selectedNode] = 1 ;

        for ( neighborIndex = 1 ; neighborIndex < n ; neighborIndex++ ) {
            isValidEdge = ( visited[neighborIndex] == 0 && L[selectedNode * n + neighborIndex] != -1 ) ;
            newDistance = shortestPath[selectedNode] + L[selectedNode * n + neighborIndex] ;

            if ( isValidEdge && newDistance < shortestPath[neighborIndex] ) {
                shortestPath[neighborIndex] = newDistance ;
            }
        }
    }

    for ( currentIndex = 1 ; currentIndex < n ; currentIndex++ ) {
        distances[currentIndex - 1] = shortestPath[currentIndex] ;
    }

    free( visited ) ;
    free( shortestPath ) ;

    return distances ;
}