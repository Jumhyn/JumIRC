#include "irc.h"

struct message;

struct message *parse_str(char *msg);

int cmdpass(char *buff, const char *pass);
int cmdnick(char *buff, const char *nick, const char *hop);
int cmduser(char *buff, const char *user, const char *host, const char *server, const char *real);
