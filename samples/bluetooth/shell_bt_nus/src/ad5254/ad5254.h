#ifndef ZEPHYR_DRIVERS_SENSOR_AD5254_H_
#define ZEPHYR_DRIVERS_SENSOR_AD5254_H_

#include <device.h>

// Function to initialize the AD5254 driver
int ad5254_init(const struct device *dev);

// Function to write to a specific register of AD5254
int ad5254_write(const struct device *dev, uint8_t reg, uint8_t value);

// Function to read from a specific register of AD5254
int ad5254_read(const struct device *dev, uint8_t reg, uint8_t *value);

#endif // ZEPHYR_DRIVERS_SENSOR_AD5254_H_