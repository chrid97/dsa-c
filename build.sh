#!/bin/bash

mkdir -p build/

if [[ "$OSTYPE" == "darwin"* ]]; then
  # macOS settings
  eval cc ./src/main.c -o ./build/program
else
  gcc ./src/main.c -o ./build/program
fi
