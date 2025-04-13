# https://github.com/zephyrproject-rtos/example-application/blob/main/app/CMakeLists.txt

cmake_minimum_required(VERSION 3.13.1)
set(BOARD qemu_x86)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app LANGUAGES C)

target_sources(app PRIVATE src/main.c)