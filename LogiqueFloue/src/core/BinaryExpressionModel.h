/*
 * BinaryExpressionModel.h
 *
 *  Created on: 25 janv. 2016
 *      Author: Dimitri
 */

#ifndef CORE_BINARYEXPRESSIONMODEL_H_
#define CORE_BINARYEXPRESSIONMODEL_H_


#include "BinaryExpression.h"
#include "Expression.h"

namespace core
{
	template<class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T>
	{
	public:
		BinaryExpressionModel(Expression<T>*, Expression<T>*, BinaryExpression<T>*);
		virtual ~BinaryExpressionModel();

		virtual T evaluate() const;
		virtual T evaluate(Expression<T>*,Expression<T>*) const;
	private:
		Expression<T>* left, *right;
		BinaryExpression<T>* _operator;
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* l, Expression<T>* r, BinaryExpression<T> *ope):
	left(l),right(r),_operator(ope)
	{
	}

	template<class T>
	BinaryExpressionModel<T>::~BinaryExpressionModel()
	{
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if(left != nullptr && right != nullptr)
			return evaluate(left, right);
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>* l,Expression<T>* r) const
	{
		if(_operator != nullptr)
			return _operator->evaluate(l, r);
	}
}
#endif
