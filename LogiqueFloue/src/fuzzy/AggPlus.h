/*
 * AggPlus.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_AGG_AGGPLUS_H_
#define FUZZY_AGG_AGGPLUS_H_

#include "../../core/Expression.h"
#include "Agg.h"

namespace fuzzy
{
	template<class T>
	class AggPlus : public Agg<T>
	{
	public:
		AggPlus(){};
		virtual ~AggPlus(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*)const;
	};

	template<class T>
	T AggPlus<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r)const
	{
		T left = l->evaluate();
		T right = r->evaluate();
		return left + right - (left * right);
	}
}

#endif /* FUZZY_AGG_AGGPLUS_H_ */
