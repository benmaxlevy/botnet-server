/*
 * =====================================================================================
 *
 *       Filename:  socket.cpp
 *
 *    Description:  Class for the server socket
 *
 *        Version:  1.0
 *        Created:  08/17/21 09:00:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben Levy (bl), general@simplexwebsites.com
 *        Company:  N/A
 *
 * =====================================================================================
 */

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

udp_socket::udp_socket(unsigned int port, unsigned int max_line)
{
	int socketfd;
	char buffer[max_line];
	struct sockaddr_in servaddr, cliaddr;
	
	//create socket file descriptor
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
	{
		perror("SOCKET UNABLE TO BE CREATED");
		exit(EXIT_FAILURE);
	}

	//make sure that the server and client address sockaddr_in's are clear
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));

	//populating server info
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(port);

	if(bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("SOCKET UNABLE TO BE BINDED TO ADDR");
		exit(EXIT_FAILURE);
	}

	int len, n;
	
	len = sizeof(cliaddr);

	n = recvfrom(sockfd, (char*)buffer, max_line, MSG_WAITALL, (struct sockaddr*) &cliaddr, &len);

	buffer[n] = '\0';

	//call status_update
	//todo!
}
