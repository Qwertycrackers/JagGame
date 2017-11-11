#include "JgPrintError.h"

void JagGame::PrintError(char *activity) {
	printf("SDL %s failed! SDL error: %s\n", activity, SDL_GetError());
}
