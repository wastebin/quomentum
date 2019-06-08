#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <SDL2/SDL.h>

#include "defs.h"

#define SDL_MIN_X 2
#define SDL_MIN_Y 0
#define SDL_MIN_Z 0
#define SDL_REQUIREDVERSION (SDL_VERSIONNUM(SDL_MIN_X, SDL_MIN_Y, SDL_MIN_Z))
#define SDL_NEW_VERSION_REJECT (SDL_VERSIONNUM(3, 0, 0))

static void init_sdl();

int main(int argc, char **argv) {
	bool ded = check_param(argc, argv, "-d") || check_param(argc, argv, "--dedicated");

	double old_time, new_time;

	init_sdl();

	puts("Surge engine " SURGE_VER_STR " (c) wastebin");

	if (ded) {
		puts("Running in dedicated mode.");
		for (;;) {
			new_time = SDL_GetTicks() / 1000.0;
		}
	} else for (;;) {
		new_time = SDL_GetTicks() / 1000.0;
	}

	return 0;
}

static void init_sdl() {
	SDL_version ver;

	SDL_GetVersion(&ver);

	printf("Found SDL version %i.%i.%i.\n", ver.major, ver.minor, ver.patch);

	if (SDL_VERSIONNUM(ver.major, ver.minor, ver.patch) < SDL_REQUIREDVERSION) {
		fprintf(stderr, "You need at least version %d.%d.%d of SDL to run this game.", SDL_MIN_X, SDL_MIN_Y, SDL_MIN_Z);
		exit(EXIT_FAILURE);
	}

	if (SDL_VERSIONNUM(ver.major, ver.minor, ver.patch) >= SDL_NEW_VERSION_REJECT) {
		fprintf(stderr, "Your version of SDL is incompatible with me.\n"
		                "You need a version in the line of %d.%d.%d\n", SDL_MIN_X, SDL_MIN_Y, SDL_MIN_Z);
		exit(EXIT_FAILURE);
	}

	if (SDL_Init(0) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}
