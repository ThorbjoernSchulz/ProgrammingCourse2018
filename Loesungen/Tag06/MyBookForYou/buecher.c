#include <stdio.h>
#include "buecher.h"

static Buecher b_tabelle[] = {
                        {"12345678", "Hans im Glück", "Gebrüder", 100, 2},
                        {"23456789", "Frau Holle", "Grimm", 200, 4}
};

static unsigned b_table_size = sizeof(b_tabelle)/sizeof(Buecher);


void print_header_buecher(void) {
    puts("------------------------------------"
         "----------------------------------");
    printf("%-15s\t%-25s\t%-25s\t%-s\t%-s\n", "ISBN", 
                                             "Name", 
                                             "Author", 
                                             "Seiten", 
                                             "Preis"); 
    puts("------------------------------------"
         "----------------------------------");
}

void print_buecher(void){
    print_header_buecher();
    for(int i = 0; i < b_table_size; ++i) {
        printf("%15s\t%25s\t%25s\t%u\t%u\n", b_tabelle[i].ISBN, 
                                            b_tabelle[i].name, 
                                            b_tabelle[i].author, 
                                            b_tabelle[i].seitenzahl, 
                                            b_tabelle[i].preis);
    }
}
