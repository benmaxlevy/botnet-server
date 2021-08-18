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

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "socket.h"
#include "types/status.h"
#include "nlohmann/json.hpp"

udp_socket::update_status(status client_status, struct sockaddr_in cliaddr)
{

}

udp_socket::udp_socket(unsigned int port, unsigned int max_line)
{
	int socketfd;
	char buffer[max_line];
	struct sockaddr_in servaddr, cliaddr;
	
	//create socket file descriptor
	if((socketfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) 
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

	if(bind(socketfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
	    perror("SOCKET UNABLE TO BE BINDED TO ADDR");
	    exit(EXIT_FAILURE);
	}
	while(true)
	{
            int len, n;
	
       	    len = sizeof(cliaddr);

	    n = recvfrom(socketfd, (char*)buffer, max_line, MSG_WAITALL, (struct sockaddr*) &cliaddr, (socklen_t*) &len);

	    buffer[n] = '\0';
		printf("Client : %s\n", buffer);
	
		//call status_update
		std::string buffer_str;
		std::stringstream buffer_ss;
		buffer_ss << buffer;
		buffer_ss >> buffer_str;
		auto json = nlohmann::json::parse(buffer_str);
		//JSON structure: {"status": "value"}
		status _status = json.at("status");
		status_update(_status , cliaddr)
	}
}
