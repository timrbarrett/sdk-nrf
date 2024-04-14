#include <ztest.h>
#include "ad5254.h"

static void test_ad5254_write_read(void) {
    const struct device *dev = device_get_binding("AD5254");
    uint8_t test_val = 0x55;
    uint8_t read_val = 0;

    // Ensure device is available
    zassert_not_null(dev, "Cannot find AD5254 device");

    // Test write operation
    zassert_ok(ad5254_write(dev, 0x01, test_val), "Failed to write to device");

    // Test read operation
    zassert_ok(ad5254_read(dev, 0x01, &read_val), "Failed to read from device");

    // Check if read value matches written value
    zassert_equal(test_val, read_val, "Read value does not match written value");
}

void test_main(void) {
    ztest_test_suite(ad5254_tests,
                     ztest_unit_test(test_ad5254_write_read));
    ztest_run_test_suite(ad5254_tests);
}