How to run the test for portsetter.cpp (updated for CO4):

DOWNLOAD FILES:
First you need to download the files to your cloud 9. The first thing you will do 
is select the green button that says clone or download. Download the zip file to
your local machine and extract those files. Then you will go to your new workspace
on cloud 9 (or whatever workspace you are using). Go to file and select "Upload 
local files..." and select the folder you just downloaded (portsetter-master). Then
make sure you rename the file "portsetter". The correct .txt files and .cpp files 
will all be there. 

TO SET THE ALIAS (NOT NEEDED FOR TESTING!):
An alias will need to be created for ./portsetter.cpp.o and the alias for it is 
setport. In terminal type nano ~/.bashrc and scroll to the bottom where you will 
type "alias setport='/home/ubuntu/workspace/portsetter/portsetter.cpp.o'"
and save the file, and that will allow you to use the setport command instead of typing 
in ./portsetter.cpp.o when running that program.
With Change Order 1, you could run the program from any folder, but for this one
you must be in the /workspace/portsetter folder or else it won't be able to read
the txt files.

FOR TESTING: 
The cpp.o (executable files) have to exist before you can execture the program. 
So in order for the executable to show up you need to run the .cpp files out of
the terminal a couple of times until they show up (just for running from the 
terminal)From the terminal, make sure you are in the right folder (/workspace/portsetter).
After you are there, all you need to do is type in "./testsetport.cpp.o" and the test 
will run showing you each individual test, with an output at the end telling you 
if they ran correctly or not. This test will only work in the /workspace/portsetter
folder, so only run it there. This will be showing the various languages as well.

FOR CHANGING ENVIROMENTAL VARIABLES
In order to change the language in the enviromental variables all you need to do
is type in "export LANGUAGE=[two letter language code]" or an appropriate code
to change the language (ending in .UTF-8 or with _MX with some country code).
You can use this export command with any of the enviromental variables for the
language to run, but it will only hold for that session in the terminal, and then
will go back to default.

Thank you!
