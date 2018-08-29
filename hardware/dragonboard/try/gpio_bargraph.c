
#include <stdio.h>
#include <stdlib.h>
#include "mraa.h"
#include <unistd.h>

typedef struct BargraphSequence {
	int pins[7];
	int timestuck[7];
} BGSequence;



int main(int argc, char** argv) {
	BGSequence bgs = { {36,12,13,69,115,507,24}, {1,2,1,3,1,1,1}};

	const char* board_name = mraa_get_platform_name();
	fprintf(stdout, "Hello mraa\n Version: %s\n Running on %s\n", mraa_get_version(), board_name);
	mraa_deinit();

	//while (1) {
	//	sleep(1);
	//}
	return MRAA_SUCCESS;
}
