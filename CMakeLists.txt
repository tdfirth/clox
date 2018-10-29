cmake_minimum_required (VERSION 3.10)
set (CMAKE_C_STANDARD 99)
project(clox C)
add_executable(
  clox
  src/main.c
  src/chunk.h
  src/chunk.c
  src/common.h
  src/compiler.h
  src/compiler.c
  src/debug.h
  src/debug.c
  src/memory.h
  src/memory.c
  src/scanner.c
  src/scanner.h
  src/value.h
  src/value.c
  src/vm.h
  src/vm.c
  src/object.h
  src/object.c
  )
