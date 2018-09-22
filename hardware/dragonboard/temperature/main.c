#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/spi/spidev.h>
#include <linux/types.h>
#include <inttypes.h>

#include "libsoc_spi.h"
#include "libsoc_gpio.h"
#include "libsoc_debug.h"

#define GPIO_CS 18

static uint8_t tx[3] = {0x01, 0x80, 0x00}, rx[3];

int main()
{
  int adc_value;
  gpio *gpio_cs;
  libsoc_set_debug(0);
  gpio_cs = libsoc_gpio_request(GPIO_CS, LS_SHARED);
  if (gpio_cs == NULL) {
    goto fail;
  }
  libsoc_gpio_set_direction(gpio_cs, OUTPUT);
  if (libsoc_gpio_get_direction(gpio_cs) != OUTPUT) {
    printf("Failed to set direction to OUTPUT!\n");
    goto fail; 
  }
  spi *spi_dev = libsoc_spi_init(0, 0); 

  if (!spi_dev) {
    printf("Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }
  libsoc_spi_set_mode(spi_dev, MODE_0);
  libsoc_spi_set_speed(spi_dev, 10000);
  libsoc_spi_set_bits_per_word(spi_dev, BITS_8);

  libsoc_gpio_set_level(gpio_cs, HIGH);
  usleep(50);
  libsoc_gpio_set_level(gpio_cs, LOW);
  libsoc_spi_rw(spi_dev, tx, rx, 3);
  libsoc_gpio_set_level(gpio_cs, HIGH);

  adc_value = (rx[1]<<8)&0b1100000000;
  adc_value |= (rx[2]&0xff);
  // 10bits 5V
  printf("%2.1f", (adc_value*5.0/1023-0.5)*100);

free:
  libsoc_spi_free(spi_dev);
fail:
  if (gpio_cs) {
    libsoc_gpio_free(gpio_cs);
  }
  return EXIT_SUCCESS;
}
