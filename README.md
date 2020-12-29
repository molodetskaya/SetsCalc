# Sets Calculator for 2021.AI

## Grammar of calculator

- expression := “[“ operator N sets “]”
- sets := set | set sets
- set := file | expression
- operator := “EQ” | “LE” | “GR”

## Details

- “file” is a file with sorted integers, one integer in a line.
- “N” is a positive integerMeaning of operators:
- EQ - returns a set of integers which consists only from values which exists in exactly N sets -arguments of operator
- LE - returns a set of integers which consists only from values which exists in less then N sets -arguments of operator
- GR - returns a set of integers which consists only from values which exists in more then N sets -arguments of operator

## How to build

```sh
$ cd SetsCalc
$ mkdir build
$ cd build
$ cmake ../
$ make
```

## How to run Sets Calculator

```sh
$ cd SetsCalc/build/scalc
$ ./scalc [EQ 3 pathToFile1 pathToFile2 pathToFile3]
```

## How to run Unit Tests

```sh
$ cd SetsCalc/build/test
$ ./scalc_test
```

## How to generate Doxygen

```sh
$ cd SetsCalc
$ doxygen doxygen_config
```