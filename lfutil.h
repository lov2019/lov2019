#ifndef LFUTIL_H
#define LFUTIL_H
#define NO_TEST // 删除这行代码以在编译中包含测试
#include <string.h>
int lfstr_indexOf(char *src, char *need) {
    if (*need == '\0') {
        return -1;
    }
    char *res = strstr(src, need));
    return res ? res - src : NULL;
}
bool lfstr_equals(char *a, char *b) {
    return !strcmp(a, b);
}
#ifndef NO_TEST
void test() {
}
#endif
#endif
