/*
 * IsHalfGaussian.h
 *
 *  Created on: 8 mars 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_ISCUMULATIVEGAUSSIAN_H_H_
#define FUZZY_ISCUMULATIVEGAUSSIAN_H_H_

#include <cmath>

namespace fuzzy
{
	template<class T>
	class IsCumulativeGaussian : public Is<T>
	{
	public:
		IsCumulativeGaussian(const T&,const T&,const T&);
		virtual ~IsCumulativeGaussian() {};

		virtual T evaluate(core::Expression<T>*) const;

	private:
		T mean,stddev,min;
	};

	template<class T>
	IsCumulativeGaussian<T>::IsCumulativeGaussian(const T& _mean, const T& _stddev,const T& _min):
	mean(_mean),stddev(_stddev),min(_min)
	{
	}

	template<class T>
	T IsCumulativeGaussian<T>::evaluate(core::Expression<T>* l) const
	{
		if(l != nullptr)
		{
			T left = l->evaluate();
			T a = (mean - left) / stddev;
			T result = 0.5 * erfc(a / pow(2.0 , 0.5));

			if(min < mean)
				return result;
			else
				return 1.0 - result;
		}
	}
}
#endif /* FUZZY_ISCUMULATIVEGAUSSIAN_H_H_ */
