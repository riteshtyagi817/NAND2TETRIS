// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm


// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.


// Put your code here.


@0
D = A
@i
M = D
@8192
D = A
@n
M = D
// looks good till now basically i = 0 and n = 8191 -- last row of the memory map(16 bits each)


(LOOP)
@KBD
D = M
@WHITE
D;JEQ
@BLACK
0;JMP


(BLACK)
@0
D = A
@i
M = D
(STB)
@SCREEN
D = A
@i
A = D + M
M = -1
@i
M = M + 1
@i
D = M
@n
D = D - M
@LOOP1
D;JEQ
@STB
0;JMP
(LOOP1)
@KBD
D = M
@WHITE
D;JEQ
@LOOP1
0;JMP


(WHITE)
@0
D = A
@i
M = D
(STW)
@SCREEN
D = A
@i
A = D + M
M = 0
@i
M = M + 1
@i
D = M
@n
D = D - M
@LOOP2
D;JEQ
@STW
0;JMP
(LOOP2)
@KBD
D = M
@LOOP2
D;JEQ
@BLACK
0;JMP




@LOOP  // might not come at this point but just writing it 
0;JMP
