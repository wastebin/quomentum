#include <string.h>

#include "defs.h"

int check_param(int argc, char **argv, const char *param) {
  for (int i = 1; i < argc; i++) {
		if (!strcmp(param, argv[i])) return i;
	}
	return 0;
}
