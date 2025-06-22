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

bool lfstrHset(LFSTR *rc, char *str) {
    if (strlen(str) + 1 > rc->size) {
        lfstrHfree(rc);
        if (!lfstrHinit(rc, strlen(str) + 1)) {
            return false;
        }
    }
    strcpy(rc->data, str);
    return true;
}

int calcRealIndex(int index, int length) {
    if (index > 0) {
        return index < length ? index : length - 1;
    }
    int rc = length + index;
    return rc >= 0 ? rc : 0;
}
#endif
