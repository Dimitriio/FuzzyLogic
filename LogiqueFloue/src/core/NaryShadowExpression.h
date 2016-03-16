/*
 * ShadowNaryExpression.h
 *
 *  Created on: 16 mars 2016
 *      Author: Dimitri
 */

#ifndef CORE_NARYSHADOWEXPRESSION_H_
#define CORE_NARYSHADOWEXPRESSION_H_

namespace core {
	template<class T>
	class NaryShadowExpression {
	public:
		NaryShadowExpression(NaryExpression<T>*);
		virtual ~NaryShadowExpression();

		virtual T evaluate(Expression<T>**);

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
	T NaryShadowExpression<T>::evaluate(Expression<T>** operands) {
		if(target != nullptr)
			return target->evaluate(operands);
		throw;
	}
}

#endif /* CORE_NARYSHADOWEXPRESSION_H_ */
