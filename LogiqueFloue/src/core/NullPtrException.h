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
public:
	NullPtrException();
	virtual const char* what() const throw();
};

NullPtrException::NullPtrException()
{
}


const char* NullPtrException::what() const throw()
{
	std::string str = "NullPtrException : ";
	str.append(std::exception::what());
	return str.c_str();
}
#endif /* CORE_NULLPTREXCEPTION_H_ */
