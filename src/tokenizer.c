//
//  tokenizer.c
//  
//
//  Created by Osvaldo Asael Nevarez.
//  this code represents the .h file methods
//
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


//null char is a string terminator

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
    
    int i = 0; //0 is false 1 is true
    
    //\v is a verticle tab
    if(c == '\0' || c == ' ' || c == '\t' || c == '\v' || c == '.'){
        i = 1; //true
        return i;
    }
    
    return 0;
    
}
    


/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
    
    
    int i = 0; //0 is false 1 is true
     
     //\v is a verticle tab
     if(c != '\0' || c != ' ' || c != '\t' || c != '\v' || c != '.'){
         i = 1; //true
         return i;
     }
     
     return 0;
    
    
}




/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words. */
char *word_start(char *str){

    while(space_char(*str)){
        if(non_space_char(*str)){
            return str;
        }
        str++;
    }
    return 0;
}





/* Returns a pointer terminator char following *word */
char *word_terminator(char *word){
   
    while(non_space_char(*word)){
        //keeps going until finds a terminator
        if(space_char(*word)){
            //if theres a terminator returns word pt
            return word;
        }

        word++;
    }
    
    return 0;
}
    


/* Counts the number of words in the string argument. */
int count_words(char *str){
    
    int totalNum=0;
   
    
    while(non_space_char(*str)){
        
        if(space_char(*str)){
            totalNum ++;
        }
        
        str++;
    }
    
    
    return totalNum;
}




/* Returns a fresly allocated new zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
    
    char *str = malloc(sizeof(char)*len);
    
    int i=0;
    while(i<(len -1)){
        str[i] = inStr[i];
        i++;
    }
    str[len] = '\0';
    
    return str;
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
    
    int len = count_words(str);
    int index =0;
    char *split =str;
    
    char **tokens = malloc(sizeof(char*)*len+1);
    
    while(*tokens){
        split = word_start(split);
        
        tokens[index] =copy_str(split, len);
        
        split = word_terminator(split);
        
        index++;
    }
    
    tokens[len] = 0;
    
    return tokens;
    
}


/* Prints all tokens. */
void print_tokens(char **tokens){
    
//    int i=0;
//    while(tokens[i] != NULL){
//        printf("%s\n", tokens[i]);
//        i++;
//    }
    
    while (*tokens){
        printf("%s", *tokens);
        tokens++;
    }
    
    printf("\n");
}





/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
    while(*tokens){
        free(*tokens);
        tokens++;
    }
    free(tokens);
}



