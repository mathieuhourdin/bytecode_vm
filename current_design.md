
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
PULL location_1
ADD 
PUSH location_2

Actually i notice that we have always maximum two values to manipulate (if we add two numbers. Either we could have a only one value to push to a specific location.).
Then the natural way could be to have two registers rg1 and rg2.
When I perform a CHARGE operation the given value is CHARGED into rg1 or rg2
When I perform a ADD, rg1 receives the value of rg2 + rg1.
When I perform a PUSH location, the value of rg1 is stored in a given location. locations are another part of the program. Values in it should be accessed by their index. Then they should be arrays.

for each program context we should have a 16 length array and two registers.

I could either directly decide in which register I put each value, or add the value just like in a linked list and consume it / field it on each instruction.



### current version of the design ###
I create a list of instructions. An instruction is an operand, which can be associated with a memory location and with a value.

A program is a  linked list of instructions which start with a START instruction and ends with a HALT.
When we run a program we loop through the linked list.

The program state has two parts :
- a register which has two sub registers : rg1 and rg2.
- a stacksegment which can hold ten values.

The instructions make state transformations :
- PUSH values from the register (rg2) to places on the stacksegment.
- PULL values from given places on the stacksegment to the register (rg2);
- CHARGE new values on the register.
- ADD the two values of the sub registers into rg2.
- START and HALT the program, which prints the last value of the register.

####Hesitations :
- Maybe I should rename the register to CPU, because it is the unit of the VM that performs the operations.
- The behavior of the two registers is not very clear for now. Currently it behaves as if CHARGE or PULL was adding a new node on a linked list, and add adds a node with the result... but simulated with only two register. rg2 is the last item of this list and rg1 the n-1 th


### 2025-10-30 iteration ###
The code is now explicitely a linked list. GPT suggested me to also try arrays. I will think later about this design choice and the possible implications.
I have implemented the logic that parses a code into a code linked list for execution.
It allows easier testing for the code.
The code is now executed based on this linked list.
Today was mainly about that. Next time i should do more design thinking about invariants, cpu etc.
I also should think about the return value of the program. What does it mean and how should it be included in the data flow.

The gpt hints for the design are the following : 
- Precise abstraction boundary between register and stack memory. Are register operationals (temporary operands) or semantics (mini state machine).
- Precise hierarchie between Program, CPU, Memory layers. It should define encapsulation (my interpretation : the instruction execution should only call the CPU that deals with memory);
- Formalize invariants
- Define more precisely an instruction such as ADD. Explain what conditions should be met when executed etc... that will help precise the model.


