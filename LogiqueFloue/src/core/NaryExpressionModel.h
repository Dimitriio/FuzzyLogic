/*
 * NaryExpressionModel.h
 *
 *  Created on: 16 mars 2016
 *      Author: Dimitri
 */

#ifndef NARYEXPRESSIONMODEL_H_
#define NARYEXPRESSIONMODEL_H_

#include "core/Expression.h"

namespace core {
	template<class T>
	class NaryExpressionModel : public Expression<T>,NaryExpression<T> {
	public:
		NaryExpressionModel(Expression<T>** ,NaryExpression<T>*);
		virtual ~NaryExpressionModel() {};

		virtual T evaluate();
		virtual T evaluate(Expression<T>**) const;

	private:
		Expression<T>** operands;
		NaryExpression<T>* _operator;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(Expression<T>** _operands ,NaryExpression<T>* ope) :
	operands(_operands),_operator(ope)
	{
	}

	template<class T>
	NaryExpressionModel<T>::~NaryExpressionModel(){
		delete _operator;
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() {
		if(_operator != nullptr)
			return _operator->evaluate(operands);
		throw;
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(Expression<T>** _operands) const {
		if(_operands != nullptr)
			return evaluate(_operands);
		throw;
	}
}

#endif /* NARYEXPRESSIONMODEL_H_ */
