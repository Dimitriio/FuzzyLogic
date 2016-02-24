/*
 * AndMin.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef ANDMIN_H
#define ANDMIN_H

#include "../core/Expression.h"
#include "Operators.h"


namespace fuzzy
{
	template<class T>
	class AndMin : public And<T>
	{
	public:
		AndMin(){};
		virtual ~AndMin(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T AndMin<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return (left >= right) ? right : left;
		}
	}
}
#endif
