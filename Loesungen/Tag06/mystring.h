#ifndef MYSTRING_H
#define MYSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

    int strlen(char * __str);
    int strncpy(char * __dest, char * __src, int len);
    int atoi(char * __str);
    char * strcat(char * __str1,char * __str2);
    int strcmp(char * __str1, char * __str2)


#ifdef __cplusplus
}
#endif

#endif /* MYSTRING_H */

