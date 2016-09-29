How to run the test for portsetter.cpp (updated for CO3):

From the terminal, make sure you are in the right folder (/workspace/portsetter).
After you are there, all you need to do is type in "./testport_es.cpp.o" and the test 
will run showing you each individual test, with an output at the end telling you 
if they ran correctly or not. This test will only work in the /workspace/portsetter
folder, so only run it there.

In order to change the language in the enviromental variables all you need to do
is type in "export LANGUAGE=[two letter language code]" or an appropriate code
to change the language (ending in .UTF-8 or with _MX with some country code).
You can use this export command with any of the enviromental variables for the
language to run, but it will only hold for that session in the terminal, and then
will go back to default.

LC_MESSAGES did not appear in my enviromental variables, so I chose to omit it 
from my program as it wouldn't allow me to test. The code would be the same as
the other variables as stated in the comments.

Note: an alias has been created for ./portsetter.cpp.o and the alias for it is 
setport. If it is not being accepted, it is because the alias need to be changed 
on the terminal. See below...
In terminal type nano ~/.bashrc and scroll to the bottom where you will type
alias setport='/home/ubuntu/workspace/portsetter/portsetter.cpp.o'
and that will allow you to use the setport command instead of typing in
./portsetter.cpp.o when running that program.
With Change Order 1, you could run the program from any folder, but for this one
you must be in the /workspace/portsetter folder or else it won't be able to read
the txt files.

Thank you!