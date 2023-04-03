#!/bin/bash

g++ task27.cpp -o task27.out
./task27.out -t
diff out.txt goldenout.txt
rm out.txt
