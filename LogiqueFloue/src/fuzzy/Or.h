/*
 * Or.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_OR_OR_H_
#define FUZZY_OR_OR_H_

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

namespace fuzzy
{
	template<class T>
	class Or : public core::BinaryExpression<T>
	{
	public:
		Or(){};
		virtual ~Or(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T Or<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
	}
}

#endif /* FUZZY_OR_OR_H_ */
