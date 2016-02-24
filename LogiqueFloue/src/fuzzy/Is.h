/*
 * Is.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_IS_IS_H_
#define FUZZY_IS_IS_H_

#include "../core/Expression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy
{
	template<class T>
	class Is : public core::UnaryExpression<T>
	{
	public:
		Is(){};
		virtual ~Is(){};

		virtual T evaluate(core::Expression<T>*) const;
	};

	template<class T>
	T  Is<T>::evaluate(core::Expression<T>* l) const
	{
	}
}

#endif /* FUZZY_IS_IS_H_ */
