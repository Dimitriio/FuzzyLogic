/*
 * SugenoDefuzz.h
 *
 *  Created on: 16 mars 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_

#include "../core/NaryExpression.h"
#include <vector>

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
		virtual ~SugenoDefuzz() {};

		virtual T evaluate(std::vector<Expression<T>*>* ) const;
	};

	template <class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*>* operands) const
	{
		T numerator, denominator = 0;

		for(core::Expression<T>* t : operands)
		{
			T w = t->evaluate();
		}
	}
}

#endif /* FUZZY_SUGENODEFUZZ_H_ */
