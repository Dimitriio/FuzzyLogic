/*
 * Expression.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

namespace core
{
	template<class T>
	class Expression
	{
	public:
		virtual ~Expression() {};

		virtual T evaluate() const=0;
	};
}

#endif
