#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define listfunction_t void(*)(xornode*)

typedef struct xornode{
    struct xornode *prevnext;
    int value; 
} xornode;

xornode *create_node(int value){
   xornode *node = (xornode *)malloc(sizeof(xornode));
   if(!node)
       return NULL;
   node->prevnext = NULL;
   node->value = value;
   return node;
}

uintptr_t get_xored_address(const xornode *const list, const xornode *const node){
    return (uintptr_t)list->prevnext^(uintptr_t)node;
}

xornode *iterate_xor_list(xornode *list, void (*function)(xornode*)){
    xornode *iter = list, *prev = NULL;
    uintptr_t next = 0;

    while((next = get_xored_address(iter, prev))){
        prev = iter;
        iter = (xornode*) next; 
        if(function)
            function(prev);
    }
    return iter;
}

int add_node(xornode *list, int value){
    if(!list)
        return 1;

    xornode *new_node = create_node(value);
    if(!new_node)
        return 1;

    xornode *last_node = iterate_xor_list(list, NULL); 
    new_node->prevnext = last_node;
    last_node->prevnext = (xornode*)get_xored_address(last_node, new_node);

    return 0;
}

void print_node(xornode *node){
    printf("%d, ", node->value);
}

void print_nodes(xornode *list){
    printf("(");
    xornode *last_node = iterate_xor_list(list, print_node);
    printf("%d)\n", last_node->value);
}

void reverse_print(xornode *list){
    print_nodes(iterate_xor_list(list, NULL));
}

void free_list(xornode *list){
    xornode *last_node = iterate_xor_list(list, (listfunction_t)free);
    free(last_node);
}

int main(void){
    xornode *list = create_node(5);
    if(add_node(list, 4))
        return 1;
    if(add_node(list, 3))
        return 1;
    if(add_node(list, 1))
        return 1;
    print_nodes(list);
    reverse_print(list);
    free_list(list);
    return 0;
}
