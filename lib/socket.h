/*
 * =====================================================================================
 *
 *       Filename:  socket.h
 *
 *    Description:  Header for socket.cpp 
 *
 *        Version:  1.0
 *        Created:  08/17/21 09:09:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben Levy (bl), general@simplexwebsites.com
 *        Company:  N/A
 *
 * =====================================================================================
 */

#ifndef SOCKET
#define SOCKET

#include <../types/status.h>
#include <netinet/in.h>

class udp_socket
{
	public:
		udp_socket(unsigned int port, unsigned int max_line);
	private:
		// this function shall be used when a client passes a message; on initial contact, the new client'sdata shall be stored in a file.
		int status_update(status client_status, struct sockaddr_in cliaddr);		
}

#endif
