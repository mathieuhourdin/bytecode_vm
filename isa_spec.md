

|Name | Category | Code | Opcode meaning | Operand type | Behavior
|-----|----------|------|----------------|--------------|---------|
| START | Program setting |STT | Begining of the program | None | Loads a new stack
| HALT | Program setting | HLT | End of the program | None | Prints a value and puts the CPU in free mode
| CHARGE | Data moving | CHG | Charge a new value in the buffer | int | The buffer is set to the operand value
| PUSH | Data moving | PSH | Push the accumulator value on the stack | Memory location | The operand address is set to the accumulator's value
| PULL | Data moving | PUL | Memory location | Sets the value of the buffer to the value of the memory at the operand address
| ADD | CPU Calcul Operations | ADD | Add the values | None | The accumulator takes the value of retained value plus the accumulator value
| CPR | CPU Calcul Operations | CPR | Compare if accumulator is bigger than buffer | None | The accumulator takes the value 1 if bigger thant buffer, or 0 
| SET | CPU Calcul Operations | SET | The value of buffer is transfered to accumulator | The accumulator takes the value of the buffer (who remain unchanged)
| JMP | Program flow management | JMP | Jump to instruction | int | The program counter jumps to the instruction with the operand index (indexed from 1)
| IF | Program flow management | IFF | Conditionnaly jump to instruction | None | If accumulator is 1, jumps to the next instruction. If false, to the next next one
