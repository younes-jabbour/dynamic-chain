#include<stdlib.h>

typedef struct Varchar_t {  
    
    char* txt ; // la chaine de caractere
    size_t MAX_SIZE ; // la taille max de la chaine de caractere
    size_t size ; // la taille effictive de la chaine de caractere

}Varchar_t;


//----------------------------- prototype des fonctions ----------------------------- //

Varchar_t create_varchar ( size_t MAX_SIZE ) ;

void ScanVarchar ( Varchar_t *ptr_varchar );

int find_word( const Varchar_t *ptr_varchar , const char* word , int n) ;

void replace_word ( Varchar_t* ptr_varchar ,const char* word1 , const char* word2 , int n );