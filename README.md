# Turing-Machine-Sim
Simulates a Turing machine with a single 2-way infinite tape.

Takes as an argument the name of a file containing the information to build a TM for some language structured as:

1. First line: start state  
2. Second line: accepting states  
3. Remaining lines: a list of transitions one line each, written as p X q Y D  
  * p - the current state of the TM  
  * X - the symbol read from the tape
  * q - the state to go to
  * Y - the symbol to write in X's place
  * D - The direction to move the tape head, represented by the letters {L,R}
