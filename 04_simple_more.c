#include <stdio.h>

#define LINES_PER_PAGE 20

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2...]\n", argv[0]);
        return 1;
    }

    char buffer[1024];
    for (int i = 1; i < argc; ++i) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            perror(argv[i]);
            continue;
        }

        int line_count = 0;
        printf("----- %s -----\n", argv[i]);
        while (fgets(buffer, sizeof(buffer), fp)) {
            fputs(buffer, stdout);
            if (++line_count == LINES_PER_PAGE) {
                printf("--More--");
                getchar();
                line_count = 0;
            }
        }

        fclose(fp);
    }
    return 0;
}
