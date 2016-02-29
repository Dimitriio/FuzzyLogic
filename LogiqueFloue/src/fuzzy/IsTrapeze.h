/*
 * IsTrapeze.h
 *
 *  Created on: 26 févr. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_ISTRAPEZE_H_
#define FUZZY_ISTRAPEZE_H_

#include "Operators.h"

namespace fuzzy
{
	template<class T>
	class IsTrapeze : public Is<T>
	{
	public:
		IsTrapeze(const T&,const T&,const T&);
		virtual ~IsTrapeze() {};

		virtual T evaluate(core::Expression<T>*) const;

	private:
		T min,max,startValue;
	};

	template<class T>
	IsTrapeze<T>::IsTrapeze(const T& _startValue, const T& _min, const T& _max):
	startValue(_startValue),min(_min),max(_max)
	{
	}

	template<class T>
	T IsTrapeze<T>::evaluate(core::Expression<T>* expression) const
	{

	}
}

#endif /* FUZZY_ISTRAPEZE_H_ */
