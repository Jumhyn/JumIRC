#include <stdlib.h>
#include "message.h"

void msg_free(struct message *msg) {
    struct params *tofree, *curr = msg->params;
    while (curr->next) {
	tofree = curr;
	curr = curr->next;
	free(tofree->param);
	free(tofree);
    }
    free(curr);
    free(msg->prefix);
    free(msg->command);
    free(msg);
}

void params_add(struct params *root, struct params *new) {
    struct params *curr = root;
    while (curr->next) {
	curr = curr->next;
    }
    curr->next = new;
}

struct params *params_get(struct params *root, int index) {
    struct params *curr = root;
    while (index && curr->next) {
	curr = curr->next;
	index--;
    }
    return curr;
}
