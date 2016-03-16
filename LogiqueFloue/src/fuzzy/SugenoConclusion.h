/*
 * SugenoConclusion.h
 *
 *  Created on: 16 mars 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_SUGENOCONCLUSION_H_
#define FUZZY_SUGENOCONCLUSION_H_

#include <vector>

#include "../core/NaryExpression.h"

namespace fuzzy {
	template<class T>
	class SugenoConclusion : public core::NaryExpression<T> {
	public:
		SugenoConclusion(std::vector<T>);
		virtual ~SugenoConclusion();

		virtual T evaluate(std::vector<Expression<T>*>*) const;

	private:
		std::vector<T> coeffs;
	};

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(std::vector<T> _coeffs):
	coeffs(_coeffs)
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<Expression<T>*>* operands) const{
		T tmp = coeffs[0];
		for(int i = 0; i < operands->size(); i++)
			tmp += operands[i]->evaluate() * coeffs[i+1];
		return tmp;
	}
}

#endif /* FUZZY_SUGENOCONCLUSION_H_ */
