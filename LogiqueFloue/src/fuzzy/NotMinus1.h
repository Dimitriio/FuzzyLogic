/*
 * NotMinus1.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_NOT_NOTMINUS1_H_
#define FUZZY_NOT_NOTMINUS1_H_

#include "../core/Expression.h"
#include "Operators.h"


namespace fuzzy
{
	template<class T>
	class NotMinus1 : public Not<T>
	{
	public:
		NotMinus1(){};
		virtual ~NotMinus1(){};

		virtual T evaluate(core::Expression<T>*) const;
	};

	template<class T>
	T NotMinus1<T>::evaluate(core::Expression<T>* l) const
	{
		if(l != nullptr)
			return (1- l->evaluate());
	}
}



#endif /* FUZZY_NOT_NOTMINUS1_H_ */
