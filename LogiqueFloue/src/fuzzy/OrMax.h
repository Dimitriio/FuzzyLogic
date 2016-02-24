/*
 * OrMax.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_OR_ORMAX_H_
#define FUZZY_OR_ORMAX_H_

#include "../Or/Or.h"

namespace fuzzy
{
	template<class T>
	class OrMax : public Or<T>
	{
	public:
		OrMax(){};
		virtual ~OrMax(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const;
	};

	template<class T>
	T OrMax<T>::evaluate(core::Expression<T>* l,core::Expression<T>* r) const
	{
		if(l != nullptr && r != nullptr)
		{
			T left = l->evaluate();
			T right = r->evaluate();
			return (left >= right)? left : right;
		}
	}
}
#endif /* FUZZY_OR_ORMAX_H_ */
