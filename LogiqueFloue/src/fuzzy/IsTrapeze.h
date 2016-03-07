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
		IsTrapeze(const T&,const T&);
		virtual ~IsTrapeze() {};

		virtual T evaluate(core::Expression<T>*) const;

	private:
		T min,max;
	};

	template<class T>
	IsTrapeze<T>::IsTrapeze(const T& _min, const T& _max):
	min(_min),max(_max)
	{
	}

	template<class T>
	T IsTrapeze<T>::evaluate(core::Expression<T>* l) const
	{
		if(l != nullptr)
		{
			T left = l->evaluate();
			if(min < max)
			{
				if(left < min)
					return 0;
				else if(left > max)
					return 1;
				else
					return (left-min)/(max-min);
			}
			else
			{
				if(left > min)
					return 0;
				else if(left < max)
					return 1;
				else
					return -(left-max)/(max-mid);
			}
		}
	}
}

#endif /* FUZZY_ISTRAPEZE_H_ */
