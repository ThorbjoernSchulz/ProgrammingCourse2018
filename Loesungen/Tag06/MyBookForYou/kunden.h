#pragma once

typedef struct Kunde {
    unsigned int kundenNr;
    char name[25];
    char vorname[25];
    char adresse[25];
    char ort_plz[25];
} Kunde;

void print_header_kunde(void);
void print_kunde(void);
