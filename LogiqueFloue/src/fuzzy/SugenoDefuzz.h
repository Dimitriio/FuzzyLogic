/*
 * SugenoDefuzz.h
 *
 *  Created on: 16 mars 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_

#include "NaryExpression.h"

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};

		T evaluate(std::vector<Expression<T>*>*) const;
	};

	template <class T>
	T SugenoDefuzz<T>::evaluate(std::vector<Expression<T>*>* operands) const
	{
		T num, denum = 0;

		for(core::Expression<T>* t : operands)
		{
			core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*) (t);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->GetOpe();
			SugenoThen<T>* sth = (SugenoThen<T>*) bse->GetTarget();

			num += t->evaluate(); // wi * zi
			denum += sth->getPremise(); // wi
		}

		if (denum != 0)
			return num/denum;
		else
			return 0;
	}
}

#endif /* FUZZY_SUGENODEFUZZ_H_ */
