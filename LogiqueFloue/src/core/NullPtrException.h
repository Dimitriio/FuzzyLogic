/*
 * NullPtrException.h
 *
 *  Created on: 1 avr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_NULLPTREXCEPTION_H_
#define CORE_NULLPTREXCEPTION_H_

#include <exception>
#include <string>

class NullPtrException: public std::exception
{
public:
	NullPtrException();
	virtual const char* what() const throw();
};
#endif /* CORE_NULLPTREXCEPTION_H_ */
