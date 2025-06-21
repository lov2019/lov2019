#ifndef LFSTR_H
#define LFSTR_H
#include <string.h>
#include <stdlib.h>
struct LFSTR {
    char *data;
    int size;
};

bool lfstrHinit(LFSTR *s, int size = 16) {
    s->data = (char *)malloc(sizeof(char) * size);
    if (s->data == NULL) {
        return false;
    }
    s->size = size;
    return true;
}

void lfstrHfree(LFSTR *s) {
    free(s->data);
    s->data = NULL;
    s->size = 0;
}
    
#endif
