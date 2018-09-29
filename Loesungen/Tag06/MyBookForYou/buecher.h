#pragma once

typedef struct Buecher {
    char ISBN[16];
    char name[25];
    char author[25];
    unsigned int seitenzahl;
    unsigned int preis;
} Buecher;

void print_header_buecher(void);
void print_buecher(void);
