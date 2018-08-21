#!/bin/sh

sudo g++ -g gen.cpp
sudo ./a.out <out1.txt> in.txt
sudo g++ -g sol1.cpp
sudo ./a.out <in.txt> out1.txt
sudo g++ -g sol2.cpp
sudo ./a.out <in.txt> out2.txt
diff out1.txt out2.txt

#Run by typing:
#chmod +x check.sh
#./check.sh
