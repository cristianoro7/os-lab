#define __LIBRARY__

#include <errno.h>
#include <unistd.h>
#include <stdio.h>

_syscall2(int, whoami, char *, name, unsigned int, size);

int main() {
    char s[30];
    whoami(s, 30);
    printf("%s", s);
    return 0;
}