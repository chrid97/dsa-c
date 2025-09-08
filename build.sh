#!/bin/bash

mkdir -p build/

if [[ "$OSTYPE" == "darwin"* ]]; then
  # macOS settings
  eval cc ./src/main.c -g -o ./build/program
else
  gcc ./src/main.c -g -o ./build/program
fi
