/*
 * UnaryExpressionModel.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef CORE_UNARYEXPRESSIONMODEL_H_
#define CORE_UNARYEXPRESSIONMODEL_H_

#include "Expression.h"
#include "UnaryExpression.h"

namespace core
{
	template<class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T>
	{
	public:
		UnaryExpressionModel(Expression<T>*, UnaryExpression<T>*);
		virtual ~UnaryExpressionModel(){};

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*) const;
	private:
		Expression<T>* operand;
		UnaryExpression<T>* _operator;
	};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* _operand, UnaryExpression<T>* ope):
		operand(_operand),_operator(ope)
	{
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operand != nullptr)
			return evaluate(operand);
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if(_operator != nullptr)
			return _operator->evaluate(o);
	}
}
#endif /* CORE_UNARYEXPRESSIONMODEL_H_ */
