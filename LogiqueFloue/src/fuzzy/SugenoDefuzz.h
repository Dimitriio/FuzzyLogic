/*
 * SugenoDefuzz.h
 *
 *  Created on: 16 mars 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_

#include "../core/NaryExpression.h"

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
		virtual ~SugenoDefuzz() {};

		virtual T evaluate(Expression<T>** ) const;
	};

	template <class T>
	T SugenoDefuzz<T>::evaluate(Expression<T>** operands) const
	{

	}
}



#endif /* FUZZY_SUGENODEFUZZ_H_ */
