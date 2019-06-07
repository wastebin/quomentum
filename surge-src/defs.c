#include "defs.h"

void init_params(params_t *params, int argc, char **argv) {
	params->basedir = ".";

	params->argc = argc;
	params->argv = argv;

	params->errstate = 0;
}
