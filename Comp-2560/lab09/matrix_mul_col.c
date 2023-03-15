#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int row = 0;
	int column = 0;

	row = atoi(argv[1]);
	column = atoi(argv[2]);

	int *A = (int *)malloc((row * column) * sizeof(int)); 
	printf("Enter the matrix elements:\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("A[%d,%d] = ", i, j);
			scanf("%d", A + i * column + j);//matrix elements is stored in row-wise
		}
		printf("\n");
	}

	//factor to multiply the matrix by
	int n = 0;
	printf("Enter a number:");
	scanf("%d", &n);

	int fd1[2];
	int fd2[2];

	for(int j = 0; j < column; ++j){
		pipe(fd1); //matrix pipe (pipe 1)
		pipe(fd2); //writing to the matrix through child process (pipe 2)

		pid_t pid = fork();
		if (pid == -1){ //not able to create child
			printf("parent PID %d => \n", getpid());
			for (int i = 0; i < row; i++) {
				*(A + i * column + j) = n * (*(A + i * column + j));
				printf("%d * A[%d,%d] = %d\n", n, i, j, *(A + i * column + j));				
			}
		}
		else if (pid > 0) { //parent process
			close(fd1[0]); //stop reading from 1st pipe
			write(fd1[1], A, sizeof(int) * row * column); //perform writing to the 1st pipe
			close(fd1[1]); //stop writing to pipe 1

			wait(0);

			close(fd2[1]); //stop writing to pipe 2 in child process
			
			read(fd2[0], A, sizeof(int) * row * column); //perform reading from the 2nd pipe
			close(fd2[0]); //stop reading through pipe 2
		}		
		else { //child process
			printf("child%d PID: %d \n", j+1, getpid());
			close(fd1[1]); //stop writing through pipe 1
			read(fd1[0], A, sizeof(int) * row * column);

			for (int i = 0; i < row; i++) {
				*(A + i * column + j) = n * (*(A + i * column + j));
				printf("%d * A[%d,%d] = %d\n", n, i, j, *(A + i * column + j));				
			}
			close(fd1[0]); //stop reading through pipe 1
			close(fd2[0]); //stop reading through pipe 2
			
			write(fd2[1], A, sizeof(int) * row * column); //update matrix back to parent process
			close(fd2[1]);//stop writing through pipe 2
			exit(0);
		}
	}
	
	wait(0);
	printf("Final matrix elements:\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("A[%d,%d] = %d\n", i, j, *(A + i * column + j));
		}
		printf("\n");
	}

	exit(0);
}

