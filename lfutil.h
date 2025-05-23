#ifndef LFUTIL_H
#define LFUTIL_H
#define NO_TEST // 删除这行代码以在编译中包含测试
#include <string.h>
#ifndef NO_TEST
#include <stdio.h>
#endif

int lfstrfind(const char *src, const char *need) {
    if (*need == '\0') {
        return -1;
    }
    char *res = strstr(src, need);
    return res != NULL ? res - src : NULL;
}

int lfstrrfind(const char *str, const char *substr) {
    // 获取原始字符串和子字符串的长度
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    // 如果子字符串为空或者原始字符串比子字符串短，则直接返回 -1
    if (substr_len == 0 || str_len < substr_len) {
        return -1;
    }

    // 从右向左遍历字符串
    for (int i = str_len - substr_len; i >= 0; i--) {
        // 比较当前位置开始的子字符串是否与目标子字符串相等
        if (strncmp(str + i, substr, substr_len) == 0) {
            return i; // 找到匹配位置
        }
    }

    // 如果没有找到匹配的子字符串，返回 -1
    return -1;
}


bool lfstr_equals(char *a, char *b) {
    return !strcmp(a, b);
}

#ifndef NO_TEST
void test() {
    const char *s = "helloWorld";
    printf("find l:%d\n", lfstrfind(
}
#endif
#endif
