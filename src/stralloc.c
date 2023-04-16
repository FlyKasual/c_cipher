#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>
#include "stralloc.h"

size_t fstralloc(char**const strptr, FILE* input) {
    const long pageSize = sysconf(_SC_PAGESIZE);
    size_t i = 0;
    int c = '\0';
    *strptr = (char*)calloc(pageSize, sizeof(char));
    if (*strptr == NULL)
        return 0;

    while((c = fgetc(input)) != '\n' && c != EOF) {
        *(*strptr + i) = c;
        ++i;
        if (i % pageSize == 0)
            *strptr = (char*)realloc(*strptr, (i + 1) * pageSize * sizeof(char));
        if (*strptr == NULL)
            return 0;
    }

    if (i % pageSize == 0) {
        *strptr = (char*)realloc(*strptr, (i * pageSize + 1) * sizeof(char));
        if (*strptr == NULL)
            return 0;
    }
    *(*strptr + i) = '\0';

    return i;
}

size_t readString(char**const strptr) {
    return fstralloc(strptr, stdin);
}
