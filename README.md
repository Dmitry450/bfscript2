# bfscript2
Low-level language, which translating in brainfuck

The language syntax consists of the following commands:

setchar c - sets the value in the current cell to c

walk n - go to n cells

change v - change the value in the current cell to v

mov n - move the value of the current cell to n cells

copy n t - copy the value of the current cell to the cell through n cells using a buffer, 
located on t cells from the current

print n - print cell values from the current to the next through n cells

split v - split string v into characters and distribute them in the following cells

alias name value - create a "variable" with the name "name" and value "value"

$name - get the value from a variable named name

Each command invocation ends with a semicolon.

In fact, these are not exactly variables, since they are used only during translation