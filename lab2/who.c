
#include <string.h>
#include <errno.h>
#include <asm/segment.h>

char msg[24];

int sys_iam(const char *name) {
    int i = 0;
    char temp[30];
    while (name[i] != '\0') {
        temp[i] = get_fs_byte(name + i);
        i++;
    }
    if (i > 23) {
        return -(EINVAL);
    }
    strcpy(msg, temp);
    return i;
}

int sys_whoami(char *name, unsigned int size) {
    int length = 0;
    while (msg[length] != '\0') {
        length++;
    }
    if (length > size) {
        return -(EINVAL);
    }
    int index = 0;
    while (msg[index] != '\0') {
        put_fs_byte(msg[i], name + index);
        index++;
    }
    name[index] = '\0';
    return index - 1;
}