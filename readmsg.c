#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "readmsg.h"

ssize_t readmsg(int fd, void *buf, size_t len, char *delim) {
    char c;
    size_t i = 0;
    char *str = (char *)buf;
    while (read(fd, &c, 1) && i < len) {
        str[i++] = c;
	int dmatch = 0, di = 0;
	while (delim[di] && delim[di++] == c && read(fd, &c, 1)) { 
	    str[i++] = c;
	}
	if (di == strlen(delim)) {
	    break;
	}
    }
    return i;
}