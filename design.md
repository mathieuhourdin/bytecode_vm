
##VM Project – Brief 0: “A Machine That Executes Instructions”

Design a system in C that can execute a series of instructions affecting a mutable internal state.

You don’t have to decide what the instructions are yet — only what the concept of an instruction and a state mean for you.

###Constraints:

The machine should be able to start, run, and stop.

Its behavior should be deterministic (same inputs → same outputs).

It should be possible to describe its state at any time (e.g., for debugging).

###Questions to help your design:

What kind of internal “state” do you imagine the machine having?

How do you represent an “instruction”?

How does time or control flow appear in your model?

What must always be true while the machine is running (your first invariants)?


## brainstorming

There is a mutable internal state and a series of instructions.
Instructions are simple phrases with keywords and scalar values (put this at this place).

The mutable internal state should allow to store some values from some operations and to use it later.
It should be a support for sequential memory management.

The state should be a stack just as in C langage. 
Each time a new instruction is executed, we have several possible cases.
A new value could be added to the state. Or values could be read and destroyed. 

Some operations fill the stack with new values, other decrease the stack and consume those values.

There is a stack pointer that says where the program is in the stack. And a code pointer that says where it is in the given instructions.

At any given time we should be able to resume the program with the same state and code position.


I have a 2 + 3 execution program.
Imagine now i have a c = 3 and then d = c + 2.
It could translate into 
CHARGE 3
PUSH location_1
CHARGE 2
CHARGE location_1
ADD 
PUSH location_2
