#include "ad5254.h"
#include <drivers/i2c.h>

#define AD5254_I2C_ADDR 0x2C // Adjust as necessary for your application

static int ad5254_write_internal(const struct device *dev, uint8_t reg, uint8_t value) {
    uint8_t buf[2] = {reg, value};
    return i2c_write(dev, buf, sizeof(buf), AD5254_I2C_ADDR);
}

static int ad5254_read_internal(const struct device *dev, uint8_t reg, uint8_t *value) {
    return i2c_write_read(dev, AD5254_I2C_ADDR, &reg, 1, value, 1);
}

int ad5254_init(const struct device *dev) {
    if (!device_is_ready(dev)) {
        return -ENODEV;
    }
    // Additional initialization steps can be implemented here
    return 0;
}

int ad5254_write(const struct device *dev, uint8_t reg, uint8_t value) {
    return ad5254_write_internal(dev, reg, value);
}

int ad5254_read(const struct device *dev, uint8_t reg, uint8_t *value) {
    return ad5254_read_internal(dev, reg, value);
}