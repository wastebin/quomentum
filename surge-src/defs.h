#ifndef DEFS_H
#define DEFS_H

//#include "stdinc.h"

#define GAME

#define SURGE_VER 0.0
#define SURGE_VER_PATCH 0
#ifndef SURGE_VER_SUFFIX
#define SURGE_VER_SUFFIX
#endif

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define SURGE_VER_STR STRINGIFY(SURGE_VER) "." STRINGIFY(SURGE_VER_PATCH) SURGE_VER_SUFFIX

#define BASENAME "files"

int check_param(int, char **, const char *);

#endif
