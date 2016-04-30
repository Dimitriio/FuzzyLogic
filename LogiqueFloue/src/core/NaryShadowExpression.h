/*
 * ShadowNaryExpression.h
 *
 *  Created on: 16 mars 2016
 *      Author: Dimitri
 */

#ifndef CORE_NARYSHADOWEXPRESSION_H_
#define CORE_NARYSHADOWEXPRESSION_H_

#include <typeinfo>
#include <vector>

#include "Expression.h"
#include "NaryExpression.h"
#include "NullPtrException.h"

namespace core {
	template<class T>
	class NaryShadowExpression : public NaryExpression<T>{
	public:
		NaryShadowExpression() {};
		NaryShadowExpression(NaryExpression<T>*);
		virtual ~NaryShadowExpression();

		virtual void setTarget(NaryExpression<T>*);
		virtual NaryExpression<T>* getTarget() const;

		virtual T evaluate(std::vector<Expression<T>*>*) const;


	private:
		NaryExpression<T>* target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* _target):
	target(_target)
	{
	}

	template<class T>
	NaryShadowExpression<T>::~NaryShadowExpression(){
		delete target;
	}

	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T>* n)
	{
		target = n;
	}

	template<class T>
	NaryExpression<T>* NaryShadowExpression<T>::getTarget() const
	{
		return target;
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>*>* operands) const {
		if(target != nullptr)
			return target->evaluate(operands);
		throw NullPtrException();
	}
}

#endif /* CORE_NARYSHADOWEXPRESSION_H_ */
