/*
 * BinaryShadowExpression.h
 *
 *  Created on: 29 févr. 2016
 *      Author: Dimitri
 */

#ifndef CORE_BINARYSHADOWEXPRESSION_H_
#define CORE_BINARYSHADOWEXPRESSION_H_

namespace core
{
	template<class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression(BinaryExpression<T>*);
		virtual ~BinaryShadowExpression();

		virtual void setTarget(BinaryExpression<T>*);
		virtual BinaryExpression<T>* getTarget() const;

		virtual T evaluate(Expression<T>*,Expression<T>*)const;

	private:
		BinaryExpression<T>* target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target):
	target(_target)
	{
	}

	template<class T>
	BinaryShadowExpression<T>::~BinaryShadowExpression()
	{
		delete target;
	}

	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T>* _target)
	{
		target = _target;
	}

	template<class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget() const
	{
		return target;
	}

	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>* l,Expression<T>* r)const
	{
		if(target != nullptr)
			return target->evaluate(l,r);
	}
}
#endif /* CORE_BINARYSHADOWEXPRESSION_H_ */
