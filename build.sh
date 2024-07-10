#!/bin/sh

cmake -G "Unix Makefiles" -S ./ -B ./build/ && cmake --build ./build/
