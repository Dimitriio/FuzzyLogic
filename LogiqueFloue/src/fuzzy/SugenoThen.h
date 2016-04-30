/*
 * SugenoThen.h
 *
 *  Created on: 30 avr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_SUGENOTHEN_H_
#define FUZZY_SUGENOTHEN_H_

#include "../core/Expression.h"

namespace fuzzy {

	template <class T>
	class SugenoThen : public Then<T>
	{
	public:
		SugenoThen(){};
		virtual ~SugenoThen(){};

		virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const;
		virtual T getPremise() const;

	private:
		mutable T premiseValue;
	};

	template<class T>
	T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const
	{
		if (l != nullptr && r != nullptr)
		{
			premiseValue = l->evaluate();
			return premiseValue * r->evaluate();
		}
	}

	template<class T>
	T SugenoThen<T>::getPremise() const {
		return premiseValue;
	}
}

#endif /* FUZZY_SUGENOTHEN_H_ */
