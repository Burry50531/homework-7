#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    char choice[4];

    while ((entry = readdir(dir))) {
        if (entry->d_type == DT_REG) {
            printf("Delete file %s? (y/n): ", entry->d_name);
            fgets(choice, sizeof(choice), stdin);
            if (choice[0] == 'y' || choice[0] == 'Y') {
                remove(entry->d_name);
            }
        }
    }

    closedir(dir);
    return 0;
}
