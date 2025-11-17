
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


### 2025-10-31 ###

I had an idea during the night for a clean encapsulation but not sure I remember.
The method to execute an instruction should not be instruction_execute, but cpu_execute(instruction);
That way it will be clear that it is the CPU that executes the instructions, and that is the orchestrator of the program execution. 
Not sure but it could even hold the memory allocation of the stack, and only resolve the address based on what it initialized first.
Maybe it should hold some kind of a context of the program execution (stack location for instance).
There is a question of the different places the CPU could hold. Should it have an output registry and two different hold registries ?

### 2025-11-11 ###

I have a few questions left about the CPU's design but first I will try to create a loop in my interpreted code. It may force certain solutions over others.
To have a loop, i need to change the data structure of the instructions. Since i need to jumb back or forward i need to have an array instead of a list. I need to use the next field for those jumps but currently the next field is used to keep all the instructions altogether so i need to have a new way to keep the code.

It seems clear that if i need to jump across multiple instructions in the code, the array is better since i dont need to loop through the linked list. I just need to do pointer arithmetic. However i could just store the next instruction pointer it would allow to jump too. Lets see.

####Result : 
I managed to create a VM that can calculate loops.

#####program design :
The program is now a vector of instruction which can be resized.
Instructions can be referenced by there index.

#####code design : 
The instructions in plane text have a 3-char code for the operation (currently named operand but it should be renamed).
The operation IF jumps to the next instruction if rg1 is true, to the second next if false.
The operation JMP jumps to the instruction with the range of the value.

#####cpu design :
The CPU holds all logic of execution.
It holds the program address
It holds a pointer to the currently executed operation
All operations except for HALT leed to another instruction
The cpu_execute method is responsible for going to the next instruction.
The CPU should always have a valid state (describe in CPU_H);

### 2025-11-13 ###

Today I've worked on the high level feedbacks given by gpt.
Basically, the vm gets more clear but some thing are still unclear.
There are few issues with the invariants that should be more central to the design to decide wether the state can be wrong sometime or not. On the ownership of the memory. And on the control flow (who decides which instruction to execute next).
However the main thing to work on is the design of the cpu, and the role of the registers (and of the stack).

It seems that my design is halfway to different kinds of existing designs : register, stack, accumulator and real CPU design (x86).
The choice to have both registers and stack makes it close to a x86 design. But I use the rg1 register just like an accumulator, thing that use to exist in some ancient designs.
Classic VMs choose either to use only registers (Lua) or only a Stack (JVM...).
I need to find a balance between a functional project and a project where i work on my architectural abilities.
What I suggest is the following : 
- Go to the end of a coherent project based on my natural intuitions : accumulator and one operand instructions. Write sufficient documentation on it (eg: document instruction) to have my own designed project with few hints from the outside.
- Compare my personal production to other ISA and VM designs to gain perspective on my choices and be able to give them another shape more suited to further needs.
- Branch to another project that mimic the behavior of a real CPU, with inspiration from the x86 ISA.
- Branch to another project which is more like a classic VM as the JVM or python interpretation system.


### 2025-11-17 

Today small session to go more clearly toward an accumulator design. Try to respect my general design intuitions with the two registers. However one should be the accumulator and the second one i should find a name for.
I also should choose if the cpu can be in an invalid state or not, if the responsability of maintaining the state belongs to the instructions or to the execution.









