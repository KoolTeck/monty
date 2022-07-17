# The Monty language

 Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
 It relies on a unique stack, with specific instructions to manipulate it.
 The goal of this project is to create an interpreter for Monty ByteCodes files.

# Compilation & Output
compile this way:
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

# Usage:

  - ./monty filename (e.g ./monty 000.m)
  - the file must contain byte codes
  - '#' is treated as a comment
