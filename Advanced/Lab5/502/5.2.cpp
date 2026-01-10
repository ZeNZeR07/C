#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void ShowAll( struct studentNode **walk ) ;
void GoNext( struct studentNode ***walk ) ;
void InsNode( struct studentNode **walk, const char n[], int a, char s, float g ) ;
void DelNode( struct studentNode **walk ) ;

int main() {
    struct studentNode *start, **now ;
    start = NULL ; now = &start ;

    InsNode( now, "one", 6, 'M', 3.11 ) ; ShowAll( &start ) ;

    InsNode( now, "two", 8, 'F', 3.22 ) ; ShowAll( &start ) ;

    GoNext( &now ) ;

    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( &start ) ;

    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( &start ) ;

    GoNext( &now ) ;

    DelNode( now ) ; ShowAll( &start ) ;

    return 0 ;
}

void ShowAll( struct studentNode **walk ) {
    while( *walk != NULL ) {
        printf( "%s ", (*walk)->name ) ;
        walk = &((*walk)->next) ;
    }
    printf( "\n" ) ;
}

void GoNext( struct studentNode ***walk ) {
    if ( (**walk) != NULL ) {
        *walk = &( (**walk)->next ) ;
    }
}


void InsNode( struct studentNode **walk, const char n[], int a, char s, float g ) {
    struct studentNode *newNode = new struct studentNode ;
    strcpy( newNode->name, n ) ;
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;

    newNode->next = *walk ;
    
    *walk = newNode ;
}

void DelNode( struct studentNode **walk ) {
    struct studentNode *temp ;
    if ( *walk != NULL ) {
        temp = *walk ;         
        *walk = temp->next ;   
        delete temp ;           
    }
}