#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){
	
	FILE *file_ptr;
	char row[300];
	char* name = "";
	char* data = "";
	char* token = "";
	
	// Opening a file and reading the text
	file_ptr = fopen(argv[1], "rt");
	
	if (file_ptr == NULL) {
		printf("Error");
	}

	// Get the data from the first row.
	fgets(row,299,file_ptr);
	
	// Read until the end of the file.
	while(!feof(file_ptr)) {
		
		int i = 0;
		int length = 0;
		name = "";
		
		// Parse the first row as experiment name and data
		for(i=0; i<strlen(row); i++){
			if(row[i] == ','){
				name = (char *) malloc(sizeof(char)*i);
				strncpy(name, row, i);
				length = strlen(row)-(i+1);
				data = (char *) malloc(sizeof(char)*length);
				strncpy(data, row+i+1, length);
				break;
			}	
		}
		
		int count = 0;
		int sum = 0;
		double average = 0.0;
		
		// Breaks the data string into a series of tokens using the delimiter.
		token = strtok(data,",");
		while (token != NULL){
			// Calculate the sum of the data in each row.
			sum += atoi(token);
			token = strtok(NULL,",");
			// Counting the number of loops, in order to obtain the average.
			count++;
		}
		// Calculate the average and cast in into a double
		average = (double) sum/count;
		
		printf("%s %.2lf \n", name, average);
		
		// Get the data from the next row
		fgets(row,299,file_ptr);
		// Releasing the specified memory.
		free(name);
		free(data);
	}
	// Closing the file.
	fclose(file_ptr);
	
}