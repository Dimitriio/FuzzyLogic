/*
 * SugenoDefuzz.h
 *
 *  Created on: 16 mars 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_SUGENODEFUZZ_H_
#define FUZZY_SUGENODEFUZZ_H_

#include "../core/NaryExpression.h"
#include "../fuzzy/SugenoThen.h"

namespace fuzzy {
	template <class T>
	class SugenoDefuzz : public core::NaryExpression<T>
	{
	public:
		SugenoDefuzz() {};
		virtual ~SugenoDefuzz() {};

		T evaluate(std::vector<core::Expression<T>*>*) const;
	};

	template <class T>
	T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>*>* operands) const
	{
		T num = 0;
		T denum = 0;
		typename std::vector<core::Expression<T>*>::const_iterator it;

		for(it = operands->begin(); it != operands->end(); it++){
			core::BinaryExpressionModel<T>*  bem = (core::BinaryExpressionModel<T>*) (*it);
			core::BinaryShadowExpression<T>* bse = (core::BinaryShadowExpression<T>*) bem->getOperator();
			SugenoThen<T>* sth = (SugenoThen<T>*) bse->getTarget();
			num += (*it)->evaluate(); // wi * zi
			denum += sth->getPremise(); // wi
			std::cout << num;
			std::cout << " - ";
			std::cout << denum;
			std::cout << std::endl;
		}

		if (denum != 0)
			return num/denum;
		else
			return 0;
	}
}

#endif /* FUZZY_SUGENODEFUZZ_H_ */
