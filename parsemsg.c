#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parsemsg.h"
#include "message.h"

struct message *parse_str(char *arg) {
  char *token;
  char *msg = strdup(arg);
  struct message *parsed = calloc(1, sizeof(struct message));
  token = strtok(msg, " ");
  if (token[0] == ':') {
    token++;
    parsed->prefix = strdup(token);
    parsed->command = strdup(token = strtok(NULL, " "));
  }
  else {
    parsed->command = strdup(token);
  }
  while ((token = strtok(NULL, " "))) {
    struct params *p = calloc(1, sizeof(struct params));
    if (token[0] == ':') {
	token[strlen(token)] = ' ';
	token++;
    }
    p->param = strdup(token);
    if (!parsed->params) {
      parsed->params = p;
    }
    else {
      params_add(parsed->params, p);
    }
  }
  free(msg);
  return parsed;
}

int cmdpass(char *buff, const char *pass) {
  int n = snprintf(buff, MAX_MESSAGELEN, "%s %s", commandArray[CMD_PASS], pass);
  if (n < MAX_MESSAGELEN - 2) {
    buff[n] = CR;
    buff[n+1] = LF;
    buff[n+2] = '\0';
    return MAX_MESSAGELEN;
  }
  buff[n-2] = CR;
  buff[n-1] = LF;
  return n;
}

int cmdnick(char *buff, const char *nick, const char *hop) {
  int n = (hop[0] == '\0') ? (snprintf(buff, MAX_MESSAGELEN, "%s %s", commandArray[CMD_NICK], nick)) : (snprintf(buff, MAX_MESSAGELEN, "%s %s %s", commandArray[CMD_NICK], nick, hop));
  if (n < MAX_MESSAGELEN - 2) {
    buff[n] =CR;
    buff[n+1] =LF;
    buff[n+2] ='\0';
    return MAX_MESSAGELEN;
  }
  buff[n-2] = CR;
  buff[n-1] = LF;
  return n;
}

int cmduser(char *buff, const char *user, const char *host, const char *server, const char *real) {
  int n = snprintf(buff, MAX_MESSAGELEN, "%s %s %s %s %s", commandArray[CMD_USER], user, host, server, real);
  if (n < MAX_MESSAGELEN - 2) {
    buff[n] = CR;
    buff[n+1] = LF;
    buff[n+2] = '\0';
    return MAX_MESSAGELEN;
  }
  buff[n-2] = CR;
  buff[n-1] = LF;
  return n;
}
