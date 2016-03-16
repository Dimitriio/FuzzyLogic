//============================================================================
// Name        : FuzzyTest.cpp
// Author      : Dimitri Reynié
// Version     :
// Copyright   : Your copyright notice
// Description : FuzzyTest in C++, Ansi-style
//============================================================================

#include <cassert>
#include <iostream>

#include "../core/BinaryExpressionModel.h"
#include "../core/Expression.h"
#include "../core/UnaryExpressionModel.h"
#include "../core/ValueModel.h"
#include "../fuzzy/AggMax.h"
#include "../fuzzy/AggPlus.h"
#include "../fuzzy/AndMin.h"
#include "../fuzzy/AndMult.h"
#include "../fuzzy/CogDefuzz.h"
#include "../fuzzy/FuzzyExpressionFactory.h"
#include "../fuzzy/IsCumulativeGaussian.h"
#include "../fuzzy/IsGaussian.h"
#include "../fuzzy/IsTrapeze.h"
#include "../fuzzy/IsTriangle.h"
#include "../fuzzy/NotMinus1.h"
#include "../fuzzy/OrMax.h"
#include "../fuzzy/OrPlus.h"
#include "../fuzzy/ThenMin.h"
#include "../fuzzy/ThenMult.h"

void testValueModel()
{
	core::ValueModel<float> vm(0.1f);
	assert(vm.evaluate()==0.1f);
	vm.setValue(0.5f);
	assert(vm.evaluate()==0.5f);
}

void testAndMin()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.5f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.9f);
	fuzzy::AndMin<float>* am = new fuzzy::AndMin<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, am);
	assert(bem->evaluate()==0.5f);
}

void testAndMult()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.2f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.6f);
	fuzzy::AndMult<float>* am = new fuzzy::AndMult<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, am);
	assert((bem->evaluate()-0.12)<4e-6);  //voir comment comparer efficacement les float
}

void testOrMax()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.15f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.3f);
	fuzzy::OrMax<float>* om = new fuzzy::OrMax<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, om);
	assert(bem->evaluate()==0.3f);
}

void testOrPlus()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.1f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.4f);
	fuzzy::OrPlus<float>* op = new fuzzy::OrPlus<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, op);
	assert(bem->evaluate()==(float)(0.1+0.4-(0.1*0.4)));
}

void testThenMin()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.1f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.4f);
	fuzzy::ThenMin<float>* tm = new fuzzy::ThenMin<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, tm);
	assert(bem->evaluate()==(0.1f));
}

void testThenMult()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.1f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.4f);
	fuzzy::ThenMult<float>* tm = new fuzzy::ThenMult<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, tm);
	assert(bem->evaluate()==(0.1f*0.4f));
}

void testAggMax()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.15f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.3f);
	fuzzy::AggMax<float>* am = new fuzzy::AggMax<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, am);
	assert(bem->evaluate()==0.3f);
}

void testAggPlus()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.15f);
	core::ValueModel<float>* r = new core::ValueModel<float>(0.3f);
	fuzzy::AggPlus<float>* ap = new fuzzy::AggPlus<float>();
	core::BinaryExpressionModel<float>* bem= new core::BinaryExpressionModel<float>(l, r, ap);
	assert(bem->evaluate()-(0.3f+0.15f-(0.3f*0.15f))<4e-6);
}

void testNotMinus1()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.15f);
	fuzzy::NotMinus1<float>* nm = new fuzzy::NotMinus1<float>();
	core::UnaryExpressionModel<float>* uem = new core::UnaryExpressionModel<float>(l,nm);
	assert(uem->evaluate()==(1-0.15f));
}

void testIsTriangle()
{
	core::ValueModel<float>* l = new core::ValueModel<float>(0.125);
	fuzzy::IsTriangle<float>* it = new fuzzy::IsTriangle<float>(0,0.5,0.5);
	core::UnaryExpressionModel<float>* uem = new core::UnaryExpressionModel<float>(l,it);
	assert(uem->evaluate()-0.25<4e-6);
}



void factoryTest()
{
	//operators
	using namespace core;
	using namespace fuzzy;

	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	AggMax<double> opAgg;
	ThenMin<double> opThen;
	CogDefuzz<double> opDefuzz;

	//fuzzy expression factory
	FuzzyExpressionFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	//membership function
	IsCumulativeGaussian<double> poor(2.5,1.5,3);
	IsGaussian<double> good(5,1.5);
	IsCumulativeGaussian<double> excellent(7.5,1.5,5);

	IsTrapeze<double> rancid(4.0,2.0);
	IsTrapeze<double> delicious(6.0,8.0);

	IsTriangle<double> cheap(0,4.17,8.33);
	IsTriangle<double> average(8.33,12.5,16.67);
	IsTriangle<double> generous(16.67,20.83,25);

	//values

	ValueModel<double> service(0.0);
	ValueModel<double> food(8.0);
	ValueModel<double> tips(0.0);

	Expression<double> *r =
			f.newAgg(
					f.newAgg(
							f.newThen(
									f.newOr(
											f.newIs(&poor,&service),
											f.newIs(&rancid,&food)
									),
									f.newIs(&cheap,&tips)
							),
							f.newThen(
									f.newIs(&good,&service),
									f.newIs(&average,&tips)
							)
					),
					f.newOr(
							f.newThen(
									f.newIs(&excellent,&service),
									f.newIs(&delicious,&food)
							),
							f.newIs(&generous,&tips)
					)
			);

	//defuzzification
	Expression<double> *system = f.newDefuzz(&tips, r, 0.0, 25.0, 1.0);


	//apply input
	float s;
	while(true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}
}

int main() {
	testValueModel();
	testAndMin();
	testAndMult();
	testOrMax();
	testOrPlus();
	testThenMin();
	testThenMult();
	testAggMax();
	testAggPlus();
	testNotMinus1();
	testIsTriangle();
	factoryTest();
	return 0;
}
