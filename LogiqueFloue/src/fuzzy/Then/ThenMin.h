/*
 * ThenMin.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_THEN_THENMIN_H_
#define FUZZY_THEN_THENMIN_H_

#include "../../core/Expression.h"
#include "../Then/Then.h"

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
		return (1-((l->evaluate()>=r->evaluate())? r->evaluate():l->evaluate()));
	}
}
#endif /* FUZZY_THEN_THENMIN_H_ */
