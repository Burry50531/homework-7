#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

int main() {
    gid_t groups[128];
    int ngroups = sizeof(groups)/sizeof(gid_t);
    char *username = getlogin();
    struct passwd *pw = getpwnam(username);

    if (getgrouplist(username, pw->pw_gid, groups, &ngroups) == -1) {
        perror("getgrouplist");
        return 1;
    }

    printf("Groups for user %s:\n", username);
    for (int i = 0; i < ngroups; i++) {
        struct group *gr = getgrgid(groups[i]);
        if (gr) {
            printf(" - %s\n", gr->gr_name);
        }
    }

    return 0;
}
