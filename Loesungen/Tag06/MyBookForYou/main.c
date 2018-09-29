#include <stdio.h>
#include "menu.h"
#include "kunden.h"
#include "buecher.h"
#include "rechnung.h"

/* Überlicherweise kommt die main Funktion in ihre
 * eigene Datei. 
 * In diesem Fall "weiss" sie von den database Funktionen
 * print_menu, get_input und handle_input.
 * Was diese Funktionen machen, dass es überhaupt
 * Studenten gibt, davon hat main keine Ahnung. 
 * Es ruft nur ein "Interface" auf. Von Implementierungen
 * muss main nichts wissen.
 */

int main(void) {
    puts("Welcome!");
    char input;
    while(input != 'q') {
        /* Erinnern Sie sich:
         * Wir haben erst die Funktionsaufrufe geschrieben,
         * dann die Funktionen implementiert!
         * Dies ist oft eine gute Art und Weise sein Programmieren
         * zu strukturieren.
         */
        print_menu();
        get_input(&input);
        handle_input(input);
    }
    puts("Good bye!");
}
