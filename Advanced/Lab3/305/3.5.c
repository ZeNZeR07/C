#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

struct student (*GetStudent( int *room ))[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;

    children = GetStudent( &group ) ;

    for ( int i = 0 ; i < group ; i++ ) {
        printf( "Room %d:\n", i + 1 ) ;
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Student %d: %s %d %c %.2f\n", 
                    j + 1, 
                    children[ i ][ j ].name, 
                    children[ i ][ j ].age, 
                    children[ i ][ j ].sex, 
                    children[ i ][ j ].gpa ) ;
        }
    }
    return 0 ;
}

struct student (*GetStudent( int *room ))[ 10 ] {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;
    
    struct student (*child)[ 10 ] = malloc( *room * sizeof( struct student[ 10 ] ) ) ;
    
    for ( int i = 0 ; i < *room ; i++ ) {
        printf( "Room %d:\n", i + 1 ) ;
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Student %d (Name Age Sex GPA): ", j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
            scanf( " %c", &child[ i ][ j ].sex ) ;
            scanf( "%f", &child[ i ][ j ].gpa ) ;
        }
    }
    return child ;
}