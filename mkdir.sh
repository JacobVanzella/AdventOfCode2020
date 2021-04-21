#!/bin/bash

# Create files and directories
for i in {1..25}
do
	mkdir "Day$(printf '%d' "$i")"
	cd "Day$(printf '%d' "$i")"
	
	echo "" > "$(printf '%d' "$i")_1.cpp"
	echo "" > "$(printf '%d' "$i")_2.cpp"
	echo "" > input.txt
	
	cd ..
done