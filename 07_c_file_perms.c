#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    char choice[4];

    while ((entry = readdir(dir))) {
        if (strstr(entry->d_name, ".c")) {
            printf("Grant read permission to others for %s? (y/n): ", entry->d_name);
            fgets(choice, sizeof(choice), stdin);
            if (choice[0] == 'y' || choice[0] == 'Y') {
                struct stat st;
                stat(entry->d_name, &st);
                chmod(entry->d_name, st.st_mode | S_IROTH);
            }
        }
    }

    closedir(dir);
    return 0;
}
