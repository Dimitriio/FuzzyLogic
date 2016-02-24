/*
 * MandaniDefuzz.h
 *
 *  Created on: 24 févr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_MANDANIDEFUZZ_H_
#define FUZZY_MANDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"

namespace fuzzy
{

	template <class T>
	class MandaniDefuzz : core::BinaryExpression<T>
	{
	public:
		MandaniDefuzz(const T&, const T&, const T&);
		virtual ~MandaniDefuzz() {};

		T evaluate(Expression<T>*, Expression<T>*) const;
		virtual T defuzz(const Shape&) const = 0;

	private:
		T min, max, step;
	};

	template <class T>
	T MandaniDefuzz<T>::evaluate(Expression<T> *s, Expression<T> *f) const
	{
		return defuzz(core::Evaluator<T>::BuildShape(min, max, step, (ValueModel<T>*)s, f));
	}
}

#endif /* FUZZY_MANDANIDEFUZZ_H_ */
