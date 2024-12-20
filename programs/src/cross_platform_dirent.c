// cross_platform_dirent.c
#include "../inc/cross_platform_dirent.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32

DIR *opendir(const char *name) {
    DIR *dir = (DIR *)malloc(sizeof(DIR));
    if (!dir) {
        perror("malloc");
        return NULL;
    }

    dir->path = (char *)malloc(strlen(name) + 3);
    if (!dir->path) {
        free(dir);
        perror("malloc");
        return NULL;
    }
    snprintf(dir->path, strlen(name) + 3, "%s\\*", name);

    dir->handle = FindFirstFile(dir->path, &dir->find_data);
    if (dir->handle == INVALID_HANDLE_VALUE) {
        free(dir->path);
        free(dir);
        return NULL;
    }

    dir->first_read = 1;
    return dir;
}

struct dirent *readdir(DIR *dirp) {
    static struct dirent entry;

    if (!dirp) {
        return NULL;
    }

    if (dirp->first_read) {
        dirp->first_read = 0;
    } else {
        if (!FindNextFile(dirp->handle, &dirp->find_data)) {
            return NULL;
        }
    }

    strncpy(entry.d_name, dirp->find_data.cFileName, MAX_PATH);
    return &entry;
}

int closedir(DIR *dirp) {
    if (!dirp) {
        return -1;
    }

    if (dirp->handle != INVALID_HANDLE_VALUE) {
        FindClose(dirp->handle);
    }

    free(dirp->path);
    free(dirp);
    return 0;
}

#else

DIR *opendir(const char *name) {
    return opendir(name);
}

struct dirent *readdir(DIR *dirp) {
    return readdir(dirp);
}

int closedir(DIR *dirp) {
    return closedir(dirp);
}

#endif