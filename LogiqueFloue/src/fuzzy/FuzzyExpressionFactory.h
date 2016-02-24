/*
 * FuzzyExpressionFactory.h
 *
 *  Created on: 24 févr. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_FUZZYEXPRESSIONFACTORY_H_
#define FUZZY_FUZZYEXPRESSIONFACTORY_H_

#include "MandaniDefuzz.h"
#include "Operators.h"

namespace fuzzy
{
	template<class T>
	class FuzzyExpressionFactory
	{
	public:
		FuzzyExpressionFactory(Not<T>*,And<T>*,Or<T>*,Then<T>*,Agg<T>*,MandaniDefuzz<T>*);
		~FuzzyExpressionFactory();

	private:
		Not<T>* notE;
		And<T>* andE;
		Or<T>* orE;
		Then<T>* thenE;
		Agg<T>* aggE;
		MandaniDefuzz<T>* mDefuzzE;
	};

	template<class T>
	FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* _not,And<T>* _and,Or<T>* _or,
			Then<T>* _then,Agg<T>* agg,MandaniDefuzz<T>* mandani):
			notE(_not),andE(_and),orE(_or),thenE(_then),mDefuzzE(mandani)
	{
	}

	template<class T>
	FuzzyExpressionFactory<T>::~FuzzyExpressionFactory()
	{
		delete notE,andE,orE,thenE,aggE,mDefuzzE;
	}
}

#endif /* FUZZY_FUZZYEXPRESSIONFACTORY_H_ */
