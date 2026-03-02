#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **walk, const char n[], int a, char s, float g ) ;
void InsNode( struct studentNode *walk, const char n[], int a, char s, float g ) ;
void DelNode( struct studentNode *walk ) ;

int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    
    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
    
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
    
    InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
    
    InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
    
    DelNode( now ) ; ShowAll( start ) ;
    
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
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;
    newNode->next = NULL ;

    if ( *walk == NULL ) {
       
        *walk = newNode ;
    } else {
        struct studentNode *temp = *walk ;
        while ( temp->next != NULL ) {
            temp = temp->next ;
        }
        
        temp->next = newNode ;
    }
    return newNode ; 
}

void InsNode( struct studentNode *walk, const char n[], int a, char s, float g ) {
    struct studentNode *newNode = new struct studentNode ;
    strcpy( newNode->name, n ) ;
    newNode->age = a ;
    newNode->sex = s ;
    newNode->gpa = g ;

    newNode->next = walk->next ; 
    walk->next = newNode ;       
}

void DelNode( struct studentNode *walk ) {
    struct studentNode *temp ;
    if ( walk->next != NULL ) {
        temp = walk->next ;      
        walk->next = temp->next ; 
        delete temp ;             
    }
}