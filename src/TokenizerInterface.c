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

int main(){
    
    char str [1000];
    
    printf("Please enter a sentance to tokenize... I will echo\n");
    fgets(str, 1000, stdin);
    printf("Echoing ... \n %s\n", str);
    
    printf("\n");
    
    char tokens[] = {'d', 'e', 'a'};
    char *pt = tokens;
    
    print_tokens(pt);
    
    
    
    
    

    

    
    
    
    
    return 0;
}
