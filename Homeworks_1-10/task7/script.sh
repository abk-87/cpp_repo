#!/bin/bash

g++ task7.cpp -o task7.out
./task7.out -t
diff out.txt goldenout.txt
rm out.txt
