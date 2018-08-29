/*
 Based on https://github.com/96boards/documentation/blob/master/consumer/guides/mraa/gpio/mraa_gpio.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#include "mraa/gpio.h"

typedef struct BargraphSequence {
	int pins[7];
	int timestuck[7];
} BGSequence;

volatile sig_atomic_t flag = 1;
void sig_handler(int signum) {
	if (signum == SIGINT) {
		fprintf(stdout, "Exiting...\n");
		flag = 0;
	}
}

#define uint8 unsigned char

int main(int argc, char** argv) {

	const char* board_name = mraa_get_platform_name();
	fprintf(stdout, "Hello mraa\n Version: %s\n Running on %s\n", mraa_get_version(), board_name);

	BGSequence bgs = { {23,24,25,26,27}, {1,2,1,3,1} };

	mraa_result_t status = MRAA_SUCCESS;
	mraa_gpio_context gpioc[5];

	signal(SIGINT, sig_handler);

	mraa_init();

	for (uint8 i=0;i<5;i++) {
		/* initialize GPIO pin */
		gpioc[i] = mraa_gpio_init(bgs.pins[i]);
		if (gpioc[i] == NULL) {
			fprintf(stderr, "Failed to initialize GPIO %d\n", bgs.pins[i]);
			mraa_deinit();
			return EXIT_FAILURE;
		}
	}

	for (uint8 i=0;i<5;i++) {
		/* set GPIO to output */
		status = mraa_gpio_dir(gpioc[i], MRAA_GPIO_OUT);
		if (status != MRAA_SUCCESS) {
			goto err_exit;
		}
	}

	/* toggle GPIO's */
	while (flag) {
		uint8 p = 0;
		for (uint8 i=0;i<5;i++) {
			if (i==0) p = 1;
			else p = 0;
			status = mraa_gpio_write(gpioc[i-1+p], 0);
			if (status != MRAA_SUCCESS) {
				goto err_exit;
			}
			status = mraa_gpio_write(gpioc[i], 1);
			if (status != MRAA_SUCCESS) {
				goto err_exit;
			}
			sleep(bgs.timestuck[i]);
		}
	}


	for (uint8 i=0;i<5;i++) {
		/* release gpio's */
		status = mraa_gpio_close(gpioc[i]);
		if (status != MRAA_SUCCESS) {
			goto err_exit;
		}
	}

	mraa_deinit();

	return EXIT_SUCCESS;

err_exit:
	mraa_result_print(status);

	mraa_deinit();

	return EXIT_FAILURE;
}
