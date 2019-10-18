# bfscript2
The language syntax consists of the following commands:

<code>setchar c</code> - sets the value in the current cell to c 

<code>walk n</code> - go to n cells

<code>change v</code> - change the value in the current cell to v (integer)

<code>mov n</code> - move the value of the current cell to n cells

<code>copy n t</code> - copy the value of the current cell to the cell located n cells from the current

using a buffer located across t cells from the current

<code>print n</code> - print cell values from the current to the next through n cells

<code>split v</code> - split string v into characters and distribute them in the following cells

<code>alias name value</code> - create an alias with the name 'name' and the value 'value'

<code>$name</code> - get the value from the alias name

<code>pointer name n</code> - create a pointer to cell n

<code>&name = c</code> - set the value of the cell at address name to 'c'

<code>\#</code> - comment

Each command invocation ends with a semicolon.

Please note that there are no name conflicts between pointers and aliases, as they stored differently

For example:

<code>alias hw "Hello, World!"; # Create hw alias</code>

<code>pointer hw 1; # Create hw pointer</code>

<code>split $hw; # Split the string stored in ALIAS hw</code>

<code>&hw = c; # Set the value of 'c' to the cell BY ADDRESS hw</code>
