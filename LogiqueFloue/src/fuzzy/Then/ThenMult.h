/*
 * ThenMult.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_THEN_THENMULT_H_
#define FUZZY_THEN_THENMULT_H_

#include "../../core/Expression.h"
#include "../Then/Then.h"

namespace fuzzy
{
	template<class T>
	class ThenMult : public Then<T>
	{
	public:
		ThenMult(){};
		virtual ~ThenMult(){};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*)const;
	};

	template<class T>
	T ThenMult<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r)const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return left * right;
		}
	}
}
#endif /* FUZZY_THEN_THENMULT_H_ */
