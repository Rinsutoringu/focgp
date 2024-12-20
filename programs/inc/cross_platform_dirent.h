#ifndef CROSS_PLATFORM_DIRENT_H
#define CROSS_PLATFORM_DIRENT_H

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#include <strsafe.h>
#include <direct.h>

typedef struct {
    HANDLE handle;
    WIN32_FIND_DATA find_data;
    char *path;
    int first_read;
} DIR;

struct dirent {
    char d_name[MAX_PATH];
};

DIR *opendir(const char *name);
struct dirent *readdir(DIR *dirp);
int closedir(DIR *dirp);

#else
#include <dirent.h>
#endif

#endif // CROSS_PLATFORM_DIRENT_H