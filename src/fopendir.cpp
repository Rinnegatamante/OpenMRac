#include "fopendir.h"
#include <SDL2/SDL.h>

FILE* fopenDir(const char* filename, const char* mode, const char* org, const char* app)
{
    const char* noPath = "";
#ifdef __vita__
	const char *path = "ux0:data/openmrac/";
#else
    const char* path = SDL_GetPrefPath(org, app);
    if (path == 0)
    {
        path = noPath;
    }
#endif
    char filepath[1024] = {0};
    snprintf(filepath, 1023, "%s%s", path, filename);
    return fopen(filepath, mode);
}
