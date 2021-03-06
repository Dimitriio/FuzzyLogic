/*
 * FuzzyExpressionFactory.h
 *
 *  Created on: 24 f�vr. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_FUZZYEXPRESSIONFACTORY_H_
#define FUZZY_FUZZYEXPRESSIONFACTORY_H_

#include "../core/BinaryShadowExpression.h"
#include "../core/Expression.h"
#include "../core/ExpressionFactory.h"
#include "../core/UnaryShadowExpression.h"
#include "../core/NaryShadowExpression.h"
#include "MamdaniDefuzz.h"
#include "SugenoDefuzz.h"
#include "SugenoConclusion.h"
#include "Operators.h"



namespace fuzzy
{
	template<class T>
	class FuzzyExpressionFactory : public core::ExpressionFactory<T>
	{
	public:
		FuzzyExpressionFactory(Not<T>*,And<T>*,Or<T>*,Then<T>*,Agg<T>*,MamdaniDefuzz<T>*);
		FuzzyExpressionFactory(Not<T>*,And<T>*,Or<T>*,Then<T>*,Agg<T>*,SugenoDefuzz<T>*, SugenoConclusion<T>*);
		~FuzzyExpressionFactory();

		core::Expression<T>* newAnd(core::Expression<T>*,core::Expression<T>*);
		core::Expression<T>* newOr(core::Expression<T>*,core::Expression<T>*);
		core::Expression<T>* newThen(core::Expression<T>*,core::Expression<T>*);
		core::Expression<T>* newAgg(core::Expression<T>*,core::Expression<T>*);
		core::Expression<T>* newDefuzz(core::Expression<T>*,core::Expression<T>*,const T&, const T&,const T&);
		core::Expression<T>* newNot(core::Expression<T>*);
		core::Expression<T>* newIs(Is<T>*,core::Expression<T>*);
		core::Expression<T>* newSugeno(std::vector<core::Expression<T>*>*);
		core::Expression<T>* newConclusion(std::vector<core::Expression<T>*>*);

		void changeAnd(And<T>*);
		void changeOr(Or<T>*);
		void changeThen(Then<T>*);
		void changeAgg(Agg<T>*);
		void changeDefuzz(MamdaniDefuzz<T>*);
		void changeNot(Not<T>*);
		void changeSugeno(SugenoDefuzz<T>*);
		void changeConclusion(SugenoConclusion<T>*);

	private:
		core::UnaryShadowExpression<T> notE;
		core::BinaryShadowExpression<T> andE;
		core::BinaryShadowExpression<T> orE;
		core::BinaryShadowExpression<T> thenE;
		core::BinaryShadowExpression<T> aggE;
		core::BinaryShadowExpression<T> defuzzE;

		core::NaryShadowExpression<T> sugenoE;
		core::NaryShadowExpression<T> conclusionE;
	};

	template<class T>
	FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* _not,And<T>* _and,Or<T>* _or,
			Then<T>* _then,Agg<T>* _agg,MamdaniDefuzz<T>* _defuzz):
			notE(_not),
			andE(_and),
			orE(_or),
			thenE(_then),
			aggE(_agg),
			defuzzE(_defuzz),
			sugenoE(),
			conclusionE()
	{
	}

	template<class T>
	FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* _not,And<T>* _and,Or<T>* _or,
			Then<T>* _then,Agg<T>* _agg,SugenoDefuzz<T>* _defuzz, SugenoConclusion<T>* _conclusion):
			notE(_not),
			andE(_and),
			orE(_or),
			thenE(_then),
			aggE(_agg),
			sugenoE(_defuzz),
			conclusionE(_conclusion)

	{
	}

	template<class T>
	FuzzyExpressionFactory<T>::~FuzzyExpressionFactory()
	{
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newAnd(core::Expression<T>* l,core::Expression<T>* r)
	{
		return this->newBinary(&andE,l,r);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newOr(core::Expression<T>* l,core::Expression<T>* r)
	{
		return this->newBinary(&orE,l,r);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newThen(core::Expression<T>* l,core::Expression<T>* r)
	{
		return this->newBinary(&thenE,l,r);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newAgg(core::Expression<T>* l,core::Expression<T>* r)
	{
		return this->newBinary(&aggE,l,r);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newDefuzz(core::Expression<T>* l,core::Expression<T>* r,const T& min,const T& max, const T& step)
	{
		((MamdaniDefuzz<T>*)defuzzE.getTarget())->setValues(min,max,step);
		return this->newBinary(&defuzzE,l,r);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newSugeno(std::vector<core::Expression<T>*>* operands)
	{
		return this->newNary(&sugenoE, operands);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newConclusion(std::vector<core::Expression<T>*>* operands)
	{
		return this->newNary(&conclusionE, operands);
	}


	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newNot(core::Expression<T>* o)
	{
		return this->newUnary(&notE,o);
	}

	template<class T>
	core::Expression<T>* FuzzyExpressionFactory<T>::newIs(Is<T>* ope,core::Expression<T>* _operand)
	{
		return this->newUnary(ope, _operand);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeAnd(And<T>* _and)
	{
		andE.setTarget(_and);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeOr(Or<T>* _or)
	{
		orE.setTarget(_or);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeThen(Then<T>* _then)
	{
		thenE.setTarget(_then);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeAgg(Agg<T>* _agg)
	{
		aggE.setTarget(_agg);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeDefuzz(MamdaniDefuzz<T>* _defuzz)
	{
		defuzzE.setTarget(_defuzz);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeNot(Not<T>* _not)
	{
		notE.setTarget(_not);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeSugeno(SugenoDefuzz<T>* _sug)
	{
		sugenoE.setTarget(_sug);
	}

	template<class T>
	void FuzzyExpressionFactory<T>::changeConclusion(SugenoConclusion<T>* _con)
	{
		conclusionE.setTarget(_con);
	}
}

#endif /* FUZZY_FUZZYEXPRESSIONFACTORY_H_ */





