#include <ctype.h>
#include <errno.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "linux/unistd.h"

int main(int argc, char *argv[])
{
	int value;

	while ((value = getopt(argc, argv, "p:g")) != -1)
		switch (value) {
		case 'p':
			if (!isdigit(optarg[0])) {
				fprintf(stderr, "Cannot parse put argument!\n");
				exit(EXIT_FAILURE);
			}
			value = atoi(optarg);
			return (syscall(__NR_krg_put, value) < 0) ? errno : 0;

		case 'g':
			value = syscall(__NR_krg_get);
			return (value < 0) ? errno : 0;

		default:
			exit(EXIT_FAILURE);
		}

	exit(EXIT_SUCCESS);
}
