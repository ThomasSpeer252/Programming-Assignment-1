# Programming-Assignment-1
COP4533 Programming Assignment 1: Matching and Verifying

Thomas Speer - UFID:80978847<br>
Paulina Gonzalez-Brito - UFID:14734443<br>



Program Instructions:<br>
---------------------------<br>
1.Compile both programs<br>
g++ verifier.cpp -o verifier<br>
g++ matcher.cpp -o matcher<br>
<br>
2.Run the matcher program, output directed to example.out<br>
./matcher < example.in > example.out<br>
<br>
3.Using pipes, Run the verifier program<br>
cat example.in example.out | ./verifier<br>

-------------------------------------------
Graph of Runtime
X-axis: n
Y-axis: t(ms)
<br><br>
<img src="graph.PNG" alt="Alt text" width="1000"/>

Task C:
The runtime graph seems to be following an exponential curve. As n increases the runtime gets exponentially larger. When n<64 the runtime is displaying as less than 1ms, after n>64 the runtime gets larger and larger.
