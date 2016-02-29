/*
 * UnaryShadowExpression.h
 *
 *  Created on: 29 févr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_UNARYSHADOWEXPRESSION_H_
#define CORE_UNARYSHADOWEXPRESSION_H_

namespace core
{
	template<class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression(UnaryExpression<T>*);
		~UnaryShadowExpression();

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
	UnaryShadowExpression<T>::~UnaryShadowExpression()
	{
		delete target;
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>* o)const
	{
		if(target != nullptr)
			return target->evaluate(o);
	}
}

#endif /* CORE_UNARYSHADOWEXPRESSION_H_ */
