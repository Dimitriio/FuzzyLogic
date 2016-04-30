/*
 * ExpressionFactory.h
 *
 *  Created on: 25 févr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_EXPRESSIONFACTORY_H_
#define CORE_EXPRESSIONFACTORY_H_

#include "BinaryExpression.h"
#include "BinaryExpressionModel.h"
#include "Expression.h"
#include "UnaryExpression.h"
#include "UnaryExpressionModel.h"
#include "NaryExpressionModel.h"
#include <vector>

namespace core
{
	template<class T>
	class ExpressionFactory
	{
	public:
		ExpressionFactory();
		~ExpressionFactory();

		Expression<T>* hold(Expression<T>*);
		Expression<T>* newUnary(UnaryExpression<T>*,Expression<T>*);
		Expression<T>* newBinary(BinaryExpression<T>*,Expression<T>*,Expression<T>*);
		Expression<T>* newNary(NaryExpression<T>*, std::vector<Expression<T>*>*);

	private:
		Expression<T>* memory;
	};

	template<class T>
	ExpressionFactory<T>::ExpressionFactory():
		memory()
	{
	}

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory()
	{
		delete memory;
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::hold(Expression<T>* expression)
	{
		*memory = *expression;
		return expression;
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o)
	{
		return hold(new UnaryExpressionModel<T>(o, ope));
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope,
			Expression<T>* l, Expression<T>* r)
	{
		return hold(new BinaryExpressionModel<T>(l,r,ope));
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*>* o)
	{
		return hold(new NaryExpressionModel<T>(o, ope));
	}
}

#endif /* CORE_EXPRESSIONFACTORY_H_ */
