#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){

	char command[100] = "";
	char temp[100];
	char *p;
	char *prompt = "Super Shell!! ";
	char *token = "";
	int i = 0;
	int j = 0;

	// The prompt when entering the unix shell, and obtaining the user's input.	
	printf("%s %s", prompt, command);
	fgets(command, sizeof(command), stdin);
	
	while(1) {
		// Copy the user's input into a temporary variable. 
		strcpy(temp, command);
		
		// Convert the user's input to uppercase, since it's case insensitive.
		for(i = 0; i<100; i++){
			command[i] = toupper(command[i]);
		}
		
		// Compare the first 11 characters of the input
		// The user's input has to equal SET PROMPT in order to change the prompt.
		if(strncmp(command, "SET PROMPT ", 11) == 0){
			p = (temp + 11);
			prompt = p;
			system(temp);
		// Compare the first 4 characters of the input
		// The user's input has to equal QUIT to exit the program.
		} else if (strncmp(command, "QUIT", 4) == 0){
			exit(0);
		} else if(j == 0) {
			system(temp);
		}
		
		j++;

		// Breaks the string into a series of tokens using the delimiter.
		token = strtok(temp,"\n");
		while(token !=NULL){
			printf("%s ", prompt);
			fgets(command, sizeof(command), stdin);
			system(command);
			token = strtok(NULL,"\n");
			if (strncmp(command, "QUIT", 4) == 0){
				exit(0);
			}
		}
	}
}
