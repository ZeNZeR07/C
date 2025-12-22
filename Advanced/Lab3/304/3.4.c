#include <stdio.h>

struct student {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
} ;

void GetStudent( struct student child[][ 10 ], int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    
    GetStudent( children, &group ) ;
    
    return 0 ;
}

void GetStudent( struct student child[][ 10 ], int *room ) {
    printf("Enter number of rooms: ");
    scanf( "%d", room ) ; 
    
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
}