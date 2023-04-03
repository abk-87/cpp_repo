#!/bin/bash

g++ task17.cpp -o task17.out
./task17.out -t
diff out.txt goldenout.txt
rm out.txt
