/*
 * OrPlus.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_OR_ORPLUS_H_
#define FUZZY_OR_ORPLUS_H_

#include "../core/Expression.h"
#include "Operators.h"

namespace fuzzy
{
	template<class T>
	class OrPlus : public Or<T>
	{
	public:
		OrPlus(){};
		virtual ~OrPlus(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T OrPlus<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return left + right - (left * right);
		}
	}
}
#endif /* FUZZY_OR_ORPLUS_H_ */
