#ifndef LFUTIL_H
#defind LFUTIL_H
#include <string.h>
int lfstr_indexOf(char *src, char *need) {
    if (*need == '\0') {
        return -1:
    }
    char *res = strstr(src, need);
    return res ? res - src : NULL;
}
#endif
