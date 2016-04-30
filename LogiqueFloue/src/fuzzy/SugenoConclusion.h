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
		virtual ~SugenoConclusion() {};

		virtual T evaluate(std::vector<core::Expression<T>*>*) const;

	private:
		std::vector<T> coeffs;
	};

	template<class T>
	SugenoConclusion<T>::SugenoConclusion(std::vector<T> _coeffs):
	coeffs(_coeffs)
	{
	}

	template<class T>
	T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*>* operands) const{
		T tmp = coeffs[0];

		typename std::vector<core::Expression<T>*>::iterator it;

		int i = 0;
		for(it = operands->begin(); it != operands->end(); it++){
			tmp += (*it)->evaluate() * coeffs[i+1];
			i++;
		}
		return tmp;
	}
}

#endif /* FUZZY_SUGENOCONCLUSION_H_ */
