#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
    struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **walk, const char n[], int a, char s, float g ) ;
void InsNode( struct studentNode *walk, const char n[], int a, char s, float g ) ;
void GoBack( struct studentNode **walk ) ;
void DelNode( struct studentNode **walk ) ;

int main() {
    struct studentNode *start, *now ;
    start = NULL ;

    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;

    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;

    GoBack( &now ) ;

    DelNode( &now ) ; ShowAll( start ) ;
    
    DelNode( &now ) ; ShowAll( start ) ;

    DelNode( &now ) ; ShowAll( start ) ;

    return 0 ;
}

void ShowAll( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s ", walk->name ) ;
        walk = walk->next ;
    }
    printf( "\n" ) ;
}

struct studentNode *AddNode( struct studentNode **walk, const char n[], int a, char s, float g ) {
    struct studentNode *newNode = new struct studentNode ;
    strcpy( newNode->name, n ) ;
    newNode->age = a; newNode->sex = s; newNode->gpa = g;
    newNode->next = NULL ;
    newNode->back = NULL ;

    if ( *walk == NULL ) {
        *walk = newNode ;
    } else {
        struct studentNode *temp = *walk ;
        while ( temp->next != NULL ) {
            temp = temp->next ;
        }
        temp->next = newNode ;
        newNode->back = temp ;
    }
    return newNode ;
}

void InsNode( struct studentNode *walk, const char n[], int a, char s, float g ) {
    if ( walk->back != NULL ) {
        struct studentNode *newNode = new struct studentNode ;
        strcpy( newNode->name, n ) ;
        newNode->age = a; newNode->sex = s; newNode->gpa = g;

        newNode->next = walk ;
        newNode->back = walk->back ;
        
        walk->back->next = newNode ;
        walk->back = newNode ;
    }
}

void GoBack( struct studentNode **walk ) {
    if ( (*walk)->back != NULL ) {
        *walk = (*walk)->back ;
    }
}

void DelNode( struct studentNode **walk ) {
    struct studentNode *curr = *walk ;
    struct studentNode *prev = curr->back ;
    struct studentNode *next = curr->next ;

    if ( prev != NULL ) prev->next = next ;
    if ( next != NULL ) next->back = prev ;

    if ( next != NULL ) {
        *walk = next ;
    } else {
        *walk = prev ;
    }

    delete curr ;
}