#include <stdlib.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char * argv[]){
	int domain = AF_INET;//Network Protocol: TCP/IP
	int type = SOCK_STREAM;//Connection-Oriented
	int protocol = 0;//Default transport: TCP for Internet connection-oriented

	int server_sd;//socket descriptor ~= file descriptor
	server_sd = socket(domain, type, protocol);
	if (server_sd == -1){
		printf("error in creating socket for The Server!\n");
		exit(1);
	}
	else{
		printf("socket has created for The Server  with sd:%d\n", server_sd);
	}

	//Binding to an address is a must for The Server!
	struct in_addr server_sin_address;
	server_sin_address.s_addr = inet_addr(argv[1]);//nslookup `hostname`
	int server_sin_port = htons(atoi(argv[2]));//larger than 1024

	struct sockaddr_in server_sin;
	server_sin.sin_family = domain;
	server_sin.sin_addr = server_sin_address;
	server_sin.sin_port = server_sin_port;
	int result = bind(server_sd, (struct sockaddr *) &server_sin, sizeof(server_sin));
	if (result == -1){
		printf("error in binding The Server to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
		exit(1);
	}
	else{
		printf("The Server bound to the address:port = %d:%d\n", server_sin.sin_addr, server_sin.sin_port);
	}

	//The Server ready to receive calls (up to 5 calls. More are rejected!) 
	if (listen(server_sd, 5) < 0) {
		perror("The Server's listening failed!\n");
		exit(1);
	}

	struct sockaddr_in client_sin;//I want to know who send the message
	int client_sin_len = sizeof(client_sin);
	while(1)
	{
		result = accept(server_sd, (struct sockaddr *) &client_sin, &client_sin_len);
		if (result == -1){
			printf("error in opening the request from client %d:%d !\n", client_sin.sin_addr, client_sin.sin_port);
			//exit(1);Do not exit. Go for the next client call
		}
		else{
			printf("The Server opened the request from client %d:%d\n", client_sin.sin_addr, client_sin.sin_port);
			while(1){

				char usernameBuffer[9];
				char passwordBuffer[6];
				int number1[1];
				int number2[1];

				recv(result, number1, sizeof(int), 0);
				printf("First number = %d\n", number1[0]);

				recv(result, number2, sizeof(int), 0);
				printf("Second number = %d\n", number2[0]);

				recv(result, usernameBuffer, sizeof(usernameBuffer), 0);
				printf("Username = %s\n", usernameBuffer);

				recv(result, passwordBuffer, sizeof(passwordBuffer), 0);
				printf("Password = %s\n", passwordBuffer);


				int sum[1];
				if (strcmp(usernameBuffer, "comp2560") == 0 && strcmp(passwordBuffer, "f2022") == 0){
					pid_t pid = fork();
					if (pid == -1) { //parent process child wasn't able to be created, we don't want to do anything here just let the parent continue
					}
					else if(pid == 0) { // child process, will perform the summation of the two inputted numbers
						printf("Child PID: %d\n", getpid());
						sum[0] = number1[0] + number2[0];
						printf("Sum is: %d\n", sum[0]);
						char expectedSize[] = "int";
						send(result, expectedSize, sizeof(expectedSize), 0);
						printf("Returning an %s to the client\n", expectedSize);
						send(result, sum, sizeof(sum), 0);
						printf("The result of the summation between %d and %d was returned to the client.\n", number1[0], number2[0]);
						exit(0); //exit this child process
					}
				}
				else{ //username and/or password was incorrect, print an error message
					char errorMessage[23] = "authentication failed!";
					char expectedResult[] = "str";
					send(result, expectedResult, sizeof(expectedResult), 0);
					send(result, errorMessage, sizeof(errorMessage), 0);
				}
			}
		}
	}

}
