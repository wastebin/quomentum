#include "defs.h"

#include <stdio.h>

static params_t params;

int main(int argc, char **argv) {
	host_params = &params;

	init_params(&params, argc, argv);

	return 0;
}
