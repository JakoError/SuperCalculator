cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 99)

add_executable(SuperCalculator Super_Calculator_Main.c matrix.h matrix.c matrix_c.c matrix_c.h hashMap.c hashMap.h high-accuracy.c high-accuracy.h "Greatest Common Divisor & Least Common Multiple.c" "Greatest Common Divisor & Least Common Multiple.h" "Gauss-Jordan Elimination.c" "Gauss-Jordan Elimination.h" "complex math.c" "complex math.h" Define_first.h quick_pow.c quick_pow.h quick_sort.c quick_sort.h "tri-math functions.c" "tri-math functions.h" "file-operate functions.c" "file-operate functions.h" Calculate.c Calculate.h)