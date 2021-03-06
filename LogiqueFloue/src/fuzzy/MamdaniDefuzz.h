/*
 * MandaniDefuzz.h
 *
 *  Created on: 24 f�vr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_MAMDANIDEFUZZ_H_
#define FUZZY_MAMDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"
#include "../core/Evaluator.h"

namespace fuzzy
{
	template <class T>
	class MamdaniDefuzz : public core::BinaryExpression<T>
	{
	public:
		MamdaniDefuzz();
		virtual ~MamdaniDefuzz() {};

		virtual void setValues(const T&, const T&, const T&);

		T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		virtual T defuzz(const typename core::Evaluator<T>::Shape&) const = 0;

	protected:
		T min, max, step;
	};

	template <class T>
	MamdaniDefuzz<T>::MamdaniDefuzz() :
	min(0), max(0), step(0)
	{
	}

	template<class T>
	void MamdaniDefuzz<T>::setValues(const T& _min, const T& _max, const T& _step)
	{
		min = _min;
		max = _max;
		step = _step;
	}

	template <class T>
	T MamdaniDefuzz<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const
	{
		return defuzz(core::Evaluator<T>::BuildShape(min, max, step, (core::ValueModel<T>*) l, r));
	}
}

#endif /* FUZZY_MAMDANIDEFUZZ_H_ */
