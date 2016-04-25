/*
 * UnaryExpressionModel.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef CORE_UNARYEXPRESSIONMODEL_H_
#define CORE_UNARYEXPRESSIONMODEL_H_

#include <typeinfo>

#include "Expression.h"
#include "NullPtrException.h"
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
		throw NullPtrException(typeid(UnaryExpressionModel).name());
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if(_operator != nullptr)
			return _operator->evaluate(o);
		throw NullPtrException(typeid(UnaryExpressionModel).name());
	}
}
#endif /* CORE_UNARYEXPRESSIONMODEL_H_ */
