/*
 * UnaryShadowExpression.h
 *
 *  Created on: 29 févr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_UNARYSHADOWEXPRESSION_H_
#define CORE_UNARYSHADOWEXPRESSION_H_

#include <typeinfo>

#include "Expression.h"
#include "NullPtrException.h"
#include "UnaryExpression.h"

namespace core
{
	template<class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression(UnaryExpression<T>*);
		virtual ~UnaryShadowExpression();

		virtual void setTarget(UnaryExpression<T>*);

		virtual T evaluate(Expression<T>*)const;

	private:
		UnaryExpression<T>* target;
	};

	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target):
	target(_target)
	{
	}

	template<class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T>* _target)
	{
		target = _target;
	}

	template<class T>
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{
		delete target;
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o)const
	{
		if(target != nullptr)
			return target->evaluate(o);
		throw NullPtrException(typeid(UnaryShadowExpression).name());
	}
}

#endif /* CORE_UNARYSHADOWEXPRESSION_H_ */
