#!/bin/bash

# Define the start and end of the range
start=800
end=200000

# Define the output file
output_file="output.txt"

# Empty the output file
> $output_file

# The loop
for ((i=start; i<=end; i+=9))
do
#   echo "Running with number $i" | tee -a $output_file
  ./rush-02 $i | cat -e >> $output_file
done

echo "Finished looping over the numbers." | tee -a $output_file
