#include <string.h>

int strlen(char * __str) {
    int len = 0;
    char tok;

    do {
        tok = __str[len];
        len++;
    } while (tok != '\0');

    return len - 1;
}

int strnCpy(char * __dest, char * __src, int len) {
    for (int i = 0; i < len; i++) {
        __dest[i] = __src[i];
    }
    return 0;
}

int itoa(char * __str){

    return 0
}

int strcmp(char *s1, char *s2){ 
    /* Solange s1 nicht auf den Nullcharakter zeigt, führen wir
       die Schleife weiter aus. */
    while (*s1 != '\0') {
        /* Wenn der Buchstabe bei s1 ein anderer ist als bei s2
           (insbesondere, wenn s2 auf den Nullcharakter zeigt und
           s1 noch nicht zuende ist), so sind die Strings nicht
           die gleichen. */
        if (*s1 != *s2) return 1;
        /* Andernfalls lassen wir sowohl s1 als auch s2 auf den
           jeweils nächsten Buchstaben zeigen. */
        s1++;
        s2++;
    }
    /* s1 zeigt nun auf den Nullcharakter. Die beiden Strings sind
       also genau dann gleich, wenn auch s2 auf den Nullcharakter
       zeigt: */
    return (*s2 != '\0');
}

char *strcat(char *s1, char *s2) {
    /* Um einen String an den anderen anzuhägen, kopieren wir einfach
       s2 an die Stelle im Speicher, an der der abschließende Null-
       charakter von s1 steht. Beispiel:
       _____________________________________________________________
        ... | H | a | l | l | o |\0 | ... | W | e | l | t |\0 | ...
       ¯¯¯¯¯¯¯^¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯^¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
             s1                            s2
       
             wird zu:
       _____________________________________________________________
        ... | H | a | l | l | o | W | e | l | t |\0 | ... | W | ...
       ¯¯¯¯¯¯¯^¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯^¯¯¯¯¯¯¯
             s1                                            s2
       Dazu verwenden wir einfach bereits geschriebene Funktionen: */
    str_cpy(s1+str_len(s1),s2);
    return s1;
}
