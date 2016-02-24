/*
 * ThenMin.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_THEN_THENMIN_H_
#define FUZZY_THEN_THENMIN_H_

#include "../core/Expression.h"
#include "Then.h"


namespace fuzzy
{
	template<class T>
	class ThenMin : public Then<T>
	{
	public:
		ThenMin(){};
		virtual ~ThenMin(){};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*)const;
	};

	template<class T>
	T ThenMin<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r)const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return (left >= right)? right : left;
		}
	}
}
#endif /* FUZZY_THEN_THENMIN_H_ */
