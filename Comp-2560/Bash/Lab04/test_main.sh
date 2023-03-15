#!/bin/bash
echo "start building main program:"
echo "compiling to assembly lines ..."
cc main.c -S
cc increment.c -S
echo "translating to opcodes ..."
cc main.s -c
cc increment.s -c
echo "statically linking all required opcodes ..."
cc main.o increment.o -o main
echo "build successfully done!"

COUNT=0
while IFS=',' read -r input output
do
    if [[ $TEMP == $output ]]; then
        COUNT=$((COUNT++))
        echo "input: $input, main: $TEMP, correct: $output ==> passed"
        echo $COUNT
        TEMP=$?
        ./main <<< $input
    else
        echo "input: $input, main: $TEMP, correct: $output  failed"
        TEMP=$?
        ./main <<< $input
    fi
done < "./test_inputs.txt"