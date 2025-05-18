#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    char *dirs[1024];
    int count = 0;

    while ((entry = readdir(dir))) {
        struct stat st;
        if (stat(entry->d_name, &st) == 0 && S_ISDIR(st.st_mode)
            && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            dirs[count++] = strdup(entry->d_name);
        }
    }

    qsort(dirs, count, sizeof(char *), compare);

    for (int i = 0; i < count; ++i) {
        printf("%s\n", dirs[i]);
        free(dirs[i]);
    }

    closedir(dir);
    return 0;
}
