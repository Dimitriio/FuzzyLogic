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
#include "MamdaniDefuzz.h"

namespace fuzzy
{
	template <class T>
	class CogDefuzz : public MandaniDefuzz<T>
	{
	public:
		CogDefuzz();
		virtual ~CogDefuzz() {};

		virtual T defuzz(const typename core::Evaluator<T>::Shape&) const;
	};

	template <class T>
	CogDefuzz<T>::CogDefuzz():
	MandaniDefuzz<T>()
	{
	}

	template <class T>
	T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape& s) const
	{
		std::vector<T> x = s.first;
		std::vector<T> y = s.second;

		T mass = 0;
		T sum_xy = 0;
		for(unsigned int i = 0; i < x.size(); i++)
		{
			sum_xy += x[i]*y[i];
			mass += y[i];
		}
		return sum_xy / mass;
	}
}

#endif /* FUZZY_COGDEFUZZ_H_ */
