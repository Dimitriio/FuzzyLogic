/*
 * IsGaussian.h
 *
 *  Created on: 7 mars 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_ISGAUSSIAN_H_
#define FUZZY_ISGAUSSIAN_H_

#include "../core/Expression.h"
#include "Operators.h"

namespace fuzzy
{
	template<class T>
	class IsGaussian : public Is<T>
	{
	public:
		IsGaussian(const T&,const T&);
		virtual ~IsGaussian() {};

		virtual T evaluate(core::Expression<T>*) const;

	private:
		T mean,stddev;
	};

	template<class T>
	IsGaussian<T>::IsGaussian(const T& _mean, const T& _stddev):
	mean(_mean),stddev(_stddev)
	{
	}

	template<class T>
	T IsGaussian<T>::evaluate(core::Expression<T>* l) const
	{
		if(l != nullptr)
		{
			T left = l->evaluate();
			T a = (left - mean) / stddev;

			return std::exp(-0.5 * pow(a,2.0));
		}
	}
}

#endif /* FUZZY_ISGAUSSIAN_H_ */
