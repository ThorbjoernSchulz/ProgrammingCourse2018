#include <stdio.h>
#include "kunden.h"

static Kunde k_tabelle[] = {
                        {1234, "Hans", "Wurst", "Strasse 2", "99999 Ort"},
                        {5678, "Haralt", "Karl", "Weg 3", "88888 Stadt"}
};

static unsigned k_table_size = sizeof(k_tabelle)/sizeof(Kunde);


void print_header_kunde(void) {
    puts("------------------------------------"
         "----------------------------------");
    printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "KundenNr", 
                                             "Name", 
                                             "Vorname", 
                                             "Adresse", 
                                             "PLZ - Ort"); 
    puts("------------------------------------"
         "----------------------------------");
}

void print_kunde(void){
    print_header_kunde();
    for(int i = 0; i < k_table_size; ++i) {
        printf("%7u\t%15s\t%15s\t%15s\t%15s\n", k_tabelle[i].kundenNr, 
                                            k_tabelle[i].name, 
                                            k_tabelle[i].vorname, 
                                            k_tabelle[i].adresse, 
                                            k_tabelle[i].ort_plz);
    }
}
