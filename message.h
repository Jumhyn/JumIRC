#include "irc.h"

struct params {
    char *param;
    struct params *next;
};

struct message {
    char *prefix;
    char *command;
    struct params *params;
};

void msg_free(struct message *msg);
void params_add(struct params *root, struct params *new);
struct params *params_get(struct params *root, int index);

