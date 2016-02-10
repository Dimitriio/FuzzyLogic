/*
 * UnaryExpression.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef CORE_UNARYEXPRESSION_H_
#define CORE_UNARYEXPRESSION_H_

#include "Expression.h"

namespace core
{
	template<class T>
	class UnaryExpression
	{
	public:
		virtual ~UnaryExpression(){};

		virtual T evaluate(Expression<T>*)const =0;
	};
}
#endif /* CORE_UNARYEXPRESSION_H_ */
