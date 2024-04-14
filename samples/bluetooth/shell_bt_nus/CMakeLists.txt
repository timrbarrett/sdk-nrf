#
# Copyright (c) 2018 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#
cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(NONE)

# NORDIC SDK APP START
target_sources(app PRIVATE
  src/main.c
  src/idle_time.h  # Add this line to include your new source file
)

target_include_directories(app PRIVATE .)
# NORDIC SDK APP END

## AD5254 driver
zephyr_library()
zephyr_library_sources_ifdef(
  CONFIG_AD5254
  ad5254.c
  #ad5254.h
)
zephyr_include_directories(.)

