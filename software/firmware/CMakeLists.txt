# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(ETH6C20MUX)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
target_link_libraries(app PUBLIC /home/grzegorz/git/ETH6C20MUX/software/firmware/libscpi/dist/libscpi.a)
target_include_directories(app PUBLIC /home/grzegorz/git/ETH6C20MUX/software/firmware/libscpi/inc)
# include($ENV{ZEPHYR_BASE}/samples/net/common/common.cmake)
