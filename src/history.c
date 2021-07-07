//
//  history.c
//  
//
//  Created by Osvaldo Asael Nevarez.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "history.h"
//#include "tokenizer.c"


typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history(){
    
    List *head = (List*)malloc(sizeof(List));
    head->root = NULL;
    return head;
    

}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str{
    
    Item *tmp = tmp = list->root;
    
    if (list == NULL){
        list->root = tmp;
        tmp->id =1;
    }
    
    else {
        tmp = (Item*)malloc(sizeof(Item));
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->str = str;
        tmp->id = tmp->id+1;
    }
    
}




/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
    Item *pt;
    pt = list->root;
    while(pt){
        if(pt->id ==id){
            return pt->str;
        }
        pt = pt->next;
    }
    return 0;
}






// *Print the entire contents of the list. */
void print_history(List *list){
    Item *pt = list->root;
    
    while (pt){
        printf("%d.- %s", pt->id, pt->str);
        pt = pt->next;
    }
}




// Free the history list and the strings it references. */
void free_history(List *list){
    while (list){
        free(list);
        list ++;
    }
    free(list);

}
