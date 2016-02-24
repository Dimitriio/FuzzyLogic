/*
 * AggMax.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_AGG_AGGMAX_H_
#define FUZZY_AGG_AGGMAX_H_

#include "../core/Expression.h"
#include "Operators.h"

namespace fuzzy
{
	template<class T>
	class AggMax : public Agg<T>
	{
	public:
		AggMax(){};
		virtual ~AggMax(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*)const;
	};

	template<class T>
	T AggMax<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r)const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		return (left >= right) ? left : right;
	}
}

#endif /* FUZZY_AGG_AGGMAX_H_ */
