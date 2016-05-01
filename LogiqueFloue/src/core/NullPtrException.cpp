/*
 * NullPtrException.cpp
 *
 *  Created on: 1 mai 2016
 *      Author: Dimitri
 */
#include "NullPtrException.h"

NullPtrException::NullPtrException()
{
}


const char* NullPtrException::what() const throw()
{
	std::string str = "NullPtrException : ";
	str.append(std::exception::what());
	return str.c_str();
}


