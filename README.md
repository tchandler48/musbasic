This is MUSBASIC.  I ported over gpl bxbasic to
run via MUSIC/SP using WATC.  The code has been tested using
MUSIC/SP download from Prof. Rene Ferland site.
	https://geronimo370/nl/vm6pext/music-sp-6-2



Installing:

To install MUSBASIC, transfer the source code into your MUSIC/SP
machine.

Once the code is transfered, then compile the MUSBASIC code by
typing:

/MUSBASIC.c
This file includes the various commands to create and 
object file.

Next type the following command:

/MUSLINK
This job will create a load file from the obj files.


Now to execute programs

You must create a execute file from each basic program
that you wish to run:

Sample is BX10.  This execute file will load MUSBASIC
and then execute BX10.BAS.
Contents:

/parm MUSBASIC BX10.BAS
/inc xmwatc
MUSBASIC n(MUSBASIC.LMOD) lcparm

(When creating new execute file, the only line you need
to change is the /parm line.  The other two stay the same.)

Sample program bx10 bas, type the command

/BX10

you should get a sample program executed.


Questions/Comments
tchandler48@gmail.com


TO DO:

Adding code to support 3270 Data Streams.  Work in
progress.


