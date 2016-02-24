/*
 * Agg.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_AGG_AGG_H_
#define FUZZY_AGG_AGG_H_

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

namespace fuzzy
{
	template<class T>
	class Agg : public core::BinaryExpression<T>
	{
	public:
		Agg(){};
		virtual ~Agg(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*)const;
	};

	template<class T>
	T Agg<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
	}
}

#endif /* FUZZY_AGG_AGG_H_ */
