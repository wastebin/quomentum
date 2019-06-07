#ifndef DEFS_H
#define DEFS_H

#define GAME

#define SURGE_VER 0.1
#define SURGE_VER_PATCH 0
#ifndef SURGE_VER_SUFFIX
#define SURGE_VER_SUFFIX
#endif

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#define SURGE_VER_STR STRINGIFY(SURGE_VER) "." STRINGIFY(SURGE_VER_PATCH) SURGE_VER_SUFFIX

#define BASENAME "files"

typedef struct {
	const char *basedir;
	const char *userdir;
	int argc;
	char **argv;
	void *membase;
	int memsize;
	int numcpus;
	int errstate;
} params_t;

void init_params(params_t *, int, char **);

extern params_t *host_params;

#include "stdinc.h"

#endif
