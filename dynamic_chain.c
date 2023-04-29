#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_chain.h"



Varchar_t create_varchar(size_t MAX_SIZE)
{
    Varchar_t new_varchar;
    new_varchar.MAX_SIZE = MAX_SIZE;
    new_varchar.txt = (char*)malloc(MAX_SIZE*sizeof(char));
    new_varchar.size = 0;

    return new_varchar;
}

void ScanVarchar(Varchar_t *ptr_varchar)
{
    puts("Tapez une phrase : ");
    fgets( ptr_varchar->txt , ptr_varchar->MAX_SIZE , stdin);
    ptr_varchar->size = strlen(ptr_varchar->txt)+1;

}

int find_word( const Varchar_t *ptr_varchar , const char* word , int n) {

        char* ptr ;
        ptr = ptr_varchar->txt ;
        int pos = 0 ;

       for ( int i = 0 ; i < n ; i++ ) {      
           
            ptr = strstr(ptr,word);
            if(ptr == NULL) return -1 ;
            ptr++ ;
       }

        ptr--;

        pos = ptr-ptr_varchar->txt;

        return pos ;
}

void replace_word ( Varchar_t* ptr_varchar ,const char* word1 , const char* word2 , int n ){
   
    int index = find_word(ptr_varchar,word1,n);
    
    if ( index == -1 )  return  ;

    if (ptr_varchar->MAX_SIZE < ptr_varchar->size-strlen(word1)+strlen(word2)+1)    
            fprintf(stderr," il ne y'a pas une taille suffisante pour faire cette operation ");

    char* ptr = &ptr_varchar->txt[index];

    memmove(ptr+strlen(word2), ptr+strlen(word1), strlen(ptr)-strlen(word1)+1);


    memcpy(ptr,word2,strlen(word2));

    ptr_varchar->size = strlen(ptr_varchar->txt) + 1 ;
}


