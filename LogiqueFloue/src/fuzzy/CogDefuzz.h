/*
 * CogDefuzz.h
 *
 *  Created on: 29 févr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_COGDEFUZZ_H_
#define FUZZY_COGDEFUZZ_H_

#include <vector>

#include "../core/Evaluator.h"
#include "MandaniDefuzz.h"

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MandaniDefuzz<T>
	{
	public:
		CogDefuzz(const T&, const T&, const T&);
		virtual ~CogDefuzz() {};

		virtual T defuzz(const typename core::Evaluator<T>::Shape&) const;
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):
	MandaniDefuzz<T>(_min, _max, _step)
	{
	}

	template <class T>
	T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape& s) const
	{
		std::vector<T> x = s.first;
		std::vector<T> y = s.second;

		T mass = 0;
		T sum_xy = 0;
		for(int i = min; i < max; i += step)
		{
			sum_xy += x[i]*y[i];
			mass += y[i];
		}

		return sum_xy / mass;
	}
}

#endif /* FUZZY_COGDEFUZZ_H_ */
