#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "readmsg.h"

ssize_t readmsg(int fd, void *buf, size_t len, char *dlim) {
    char c;
    ssize_t n;
    size_t i = 0;
    char *str = (char *)buf;
    while ((n = read(fd, &c, 1)) > 0 && i < len) {
        str[i++] = c;
	int di = 0;
	while (dlim[di] && dlim[di++] == c && (n = read(fd, &c, 1)) > 0) { 
	    str[i++] = c;
	}
	if (di == strlen(delim) || n < 0) {
	    break;
	}
    }
    if (n < 0) {
	return n;
    }
    return i;
}
