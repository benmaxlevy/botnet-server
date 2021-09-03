/*
 * =====================================================================================
 *
 *       Filename:  status.h
 *
 *    Description:  Enum for status passed from clients.  
 *
 *        Version:  1.0
 *        Created:  08/17/21 09:34:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ben Levy (bl), general@simplexwebsites.com
 *        Company:  N/A
 *
 * =====================================================================================
 */
#ifndef TYPES_H
#define TYPES_H
enum status {ok, initial, recieved, execute, execute_w_error};
#endif
