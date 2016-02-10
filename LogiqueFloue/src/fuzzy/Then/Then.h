/*
 * THEN.h
 *
 *  Created on: 26 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_THEN_THEN_H_
#define FUZZY_THEN_THEN_H_

#include "../../core/BinaryExpression.h"
#include "../../core/Expression.h"
#include "../Or/Or.h"

namespace fuzzy
{
	template<class T>
	class Then : public core::BinaryExpression<T>
	{
	public:
		Then(){};
		virtual ~Then(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T Then<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
	}
}

#endif /* FUZZY_THEN_THEN_H_ */
