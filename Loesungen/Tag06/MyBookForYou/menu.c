#include <stdio.h>
#include "kunden.h"
#include "buecher.h"
#include "menu.h"

void print_menu(void) {
    puts("[k] Kunden");
    puts("[b] Bücher");
    puts("[q] exit");
}

void print_sub_menu(void) {
    puts("[i] einfügen");
    puts("[e] bearbeiten");
    puts("[d] löschen");
    puts("[b] zurück (back)");
}

// Diese Funktion 'leert' den Eingabebuffer.
void clear_input_buffer(void) {
    char ch = 0;
    while(ch != '\n')
        ch = getchar();
}

void get_input(char *input) {
    scanf("%c", input);
    clear_input_buffer();
}

void handle_input_submenu_kunden(char input) {
    print_kunde();
    switch(input) {
        case 'i':
             
            break;
        case 'e':
            
            break;
        case 'd':
            
            break;
         case 'b':
            break;
        default:
            break;
    }
}

void handle_input_submenu_buecher(char input) {
    print_buecher();
    switch(input) {
        case 'i':
             
            break;
        case 'e':
            
            break;
        case 'd':
            
            break;
         case 'b':
            break;
        default:
            break;
    }
}


void handle_input(char input) {
    switch(input) {
        case 'k':
            input = '\0';
            print_sub_menu();
            get_input(&input);
            handle_input_submenu_kunden(input);
            break;
        case 'b':
            input = '\0';
            print_sub_menu();
            get_input(&input);
            handle_input_submenu_buecher(input);
            break;
        default:
            break;
    }
}

