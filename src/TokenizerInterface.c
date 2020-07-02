//
//  TokenizerInterface.c
//
//  
//
//  Created by Osvaldo Asael Nevarez  on 6/28/20.
//
#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "tokenizer.c"



#define SIZE 100


int main(){
    
    char str [SIZE];
    
    printf("Please enter a sentance to tokenize... I will echo\n");
    fgets(str, SIZE, stdin);
    printf("Echoing ... \n %s\n", str);
    
    printf("\n");
    
    
    char **theTokens;
    
    theTokens = tokenize(str);
    print_tokens(theTokens);
    
    
    
    

    

    
    
    
    
    return 0;
}

