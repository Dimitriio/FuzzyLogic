/*
 * MandaniDefuzz.h
 *
 *  Created on: 24 f�vr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_MANDANIDEFUZZ_H_
#define FUZZY_MANDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"
#include "../core/Evaluator.h"

namespace fuzzy
{
	template <class T>
	class MandaniDefuzz : public core::BinaryExpression<T>
	{
	public:
		MandaniDefuzz(const T&, const T&, const T&);
		virtual ~MandaniDefuzz() {};

		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		virtual T defuzz(const typename core::Evaluator<T>::Shape&) const = 0;

	protected:
		T min, max, step;
	};

	template <class T>
	MandaniDefuzz<T>::MandaniDefuzz(const T& _min, const T& _max, const T& _step) :
	min(_min), max(_max), step(_step)
	{
	}

	template <class T>
	T MandaniDefuzz<T>::evaluate(core::Expression<T> *s, core::Expression<T> *f) const
	{
		return defuzz(core::Evaluator<T>::BuildShape(min, max, step, (core::ValueModel<T>*)s, f));
	}
}

#endif /* FUZZY_MANDANIDEFUZZ_H_ */
