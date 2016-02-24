/*
 * AndMult.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_AND_ANDMULT_H_
#define FUZZY_AND_ANDMULT_H_

#include "../core/Expression.h"
#include "And.h"

namespace fuzzy
{
	template<class T>
	class AndMult : public And<T>
	{
	public:
		AndMult(){};
		virtual ~AndMult(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;

	};

	template<class T>
	T AndMult<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return left * right;
		}
	}
}
#endif /* FUZZY_AND_ANDMULT_H_ */
