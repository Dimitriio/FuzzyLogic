/*
 * And.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_AND_AND_H_
#define FUZZY_AND_AND_H_

#include "../../core/BinaryExpression.h"
#include "../../core/Expression.h"

namespace fuzzy
{
	template<class T>
	class And : public core::BinaryExpression<T>
	{
	public:
		And(){};
		virtual ~And(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T  And<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
	}
}
#endif /* FUZZY_AND_AND_H_ */
