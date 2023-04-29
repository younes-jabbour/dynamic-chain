#include<stdio.h>
#include<stdlib.h>
#include"dynamic_chain.h"

int main () {  

    size_t n = 100 ;    
    Varchar_t New_var ;
    int rep = 2 ;
    char word[6] = {"maroc"};
    
    New_var = create_varchar(n);

/* le message c'est : je suis au maroc c'est une belle pays, i'm in maroc it's a beautiful contry*/
    
    ScanVarchar(&New_var);

    if(find_word(&New_var,word,rep) == -1)
            printf(" la %d-ieme occurence du mot \" %s \" n'existe pas. ",rep,word);
    else{
       replace_word(&New_var,"maroc","morroco",2);
       printf(" le Text apres modification : ");
       printf("\n%s",New_var.txt);
    }
    
    return 0 ;
}