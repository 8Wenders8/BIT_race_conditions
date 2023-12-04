# BIT_race_conditions
Semestral Thesis for Information Technologies Security class about Race Conditions in Linux filesystem.

Testing was done in a Debian 12 VM with two users. 

## Sequential
One of the users owns the binaries and the book.txt 
The second users (attacker) runs the exploits while the first user runs the binaries.
There is a provided time window for the attacker to run the exploit.

Compile just with `gcc code.c -o code`

## Locking
Compile with `gcc code.c -o code -lpthread` and just run.
