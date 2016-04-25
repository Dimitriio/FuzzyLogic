/*
 * NullPtrException.h
 *
 *  Created on: 1 avr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_NULLPTREXCEPTION_H_
#define CORE_NULLPTREXCEPTION_H_

#include <iostream>
#include <sstream>
#include <exception>

class NullPtrException: public std::exception
{
private:
	std::string msg;

public:
	NullPtrException(std::string);
	virtual ~NullPtrException() {};
	virtual const char* what() const throw();
};

NullPtrException::NullPtrException(std::string className)
{
	std::ostringstream oss;
	oss << "Null Pointer in class : " << className;
	msg = oss.str();
}


const char* NullPtrException::what() const throw()
{

	return msg.c_str();
}
#endif /* CORE_NULLPTREXCEPTION_H_ */
