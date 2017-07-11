/*-----------------------------
This library provides functions to capture video with the picamera
and to stream it with gstreamer.
To use it, you should create a process wich is responsible of the video capture, and a process responsible of the streaming. 
The communication between the two proccess should be handled with a pipe

Author : Odysseus
------------------------------*/ 


#include <stdio.h>
#include <stdlib.h>


static char* itoa(int i) {
	char s[15];
	sprintf(s,"%d",i);
	return s;
}


int capture(int width, int height, int fps, int bitrate){
	char* args[]={	"raspivid",
			"-t",
			"0",
			"-w",
			itoa(with),
			"-h",
			itoa(height),
			"-fps",
			itoa(fps),
			"-b",
			itoa(bitrate),
			"-o",
			NULL };
	if(execv("/bin/raspivid", args)== -1) {
		perror("capture.execv");
		exit(EXIT_FAILURE)
	}
	else {
		#ifdef DEBUG
			
		#endif
			
		
						
	
	
}

