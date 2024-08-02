#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>

void print_usage(char *argv[]){
    printf("Usage: %s -n -f <database file>\n");
    printf("\t -n - create new database file\n");
    printf("\t -f - (required) path to database\n");
}

int main(int argc, char *argv[]) { 
	char *filepath = NULL;
	bool newfile = false;
	int case;

	while ((case = getopt(argc, argv, "nf:")) != -1) {
		switch (case) {
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath = optarg;
				break;
			case '?':
				printf("Unknown option -%c\n", case);
				break;
			default:
				return -1;
		}
	}

    if (filepath == NULL) {
        printf("Filepath is a required argument\n");
        print_usage(argv);

        return 0;
    }
}