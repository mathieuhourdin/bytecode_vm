

|Name | Category | Code | Opcode meaning | Operand type | Behavior
|-----|----------|------|----------------|--------------|---------|
| START | Program setting |STT | Begining of the program | None | Loads a new stack
| HALT | Program setting | HLT | End of the program | None | Prints a value and puts the CPU in free mode
| CHARGE | Data moving | CHG | Charge a new value in the buffer | int | The buffer is set to the operand value
| PUSH | Data moving | PSH | Push the accumulator value on the stack | Memory location | The operand address is set to the accumulator's value
| PULL | Data moving | PUL | Memory location | Memory Location | Sets the value of the buffer to the value of the memory at the operand address
| ADD | CPU Calcul Operations | ADD | Add the values | None | The accumulator takes the value of retained value plus the accumulator value
| CPR | CPU Calcul Operations | CPR | Compare if accumulator is bigger than buffer | None | The accumulator takes the value 1 if bigger thant buffer, or 0 
| SET | CPU Calcul Operations | SET | The value of buffer is transfered to accumulator | None | The accumulator takes the value of the buffer (who remain unchanged)
| JMP | Program flow management | JMP | Jump to instruction | int | The program counter jumps to the instruction with the operand index (indexed from 1)
| IF | Program flow management | IFF | Conditionnaly jump to instruction | None | If accumulator is 1, jumps to the next instruction. If false, to the next next one




A few example of ISA transcription from language like C : 
1 assignation
```a = 2;```
```CHG 2
SET
PUSH STACK_0```

2 assignation of sum
```c = 3 + 4;```
```CHG 3
SET
CHG 4
ADD
PUSH STACK_1```

3 for loop
```c = 1;
while (int i = 0; i < 10; i++) {
  c = 2 * c;
}```
```CHG 1
SET
PSH STACK_3
CHG 0
SET
PSH STACK_2
CHG 11
SET
PUL STACK_2
CPR
IFF
JMP 25
JMP 36
PUL STACK_3
SET
PUL STACK_3
ADD
PSH STACK_3
PUL STACK_2
SET
CHG 1
ADD
PSH STACK_2
JMP 18```






