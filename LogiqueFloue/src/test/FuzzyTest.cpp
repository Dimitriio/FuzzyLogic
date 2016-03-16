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

#include "../fuzzy/Fuzzy.h"
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
	_FuzzyExpressionFactory f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	//membership function
	IsTriangle<double> tF(0.0,5.0,10.0);
	IsTriangle<double> tNR(5.0,10.0,15.0);
	IsTriangle<double> tC(10.0,15.0,20.0);

	IsTriangle<double> dtF(-2.0,-1.0,0.0);
	IsTriangle<double> dtZ(-1.0,0.0,1.0);
	IsTriangle<double> dtC(0.0,-1.0,-2.0);

	//values

	ValueModel<double> temp(6.5);
	ValueModel<double> dtemp(0.9);
	ValueModel<double> tips(0.0);

	Expression<double> *r =
			f.newAgg(
					f.newAgg(
							f.newThen(
									f.newOr(
											f.newIs(&tF,&temp),
											f.newIs(&dtF,&dtemp)
									),
									f.newIs(&tC,&tips)
							),
							f.newThen(
									f.newOr(
											f.newIs(&tF,&temp),
											f.newIs(&dtZ,&dtemp)
									),
									f.newIs(&tC,&tips)
							)
					),
					f.newAgg(
							f.newThen(
									f.newOr(
											f.newIs(&tNR,&temp),
											f.newIs(&dtF,&dtemp)
									),
									f.newIs(&tC,&tips)
							),
							f.newThen(
									f.newOr(
											f.newIs(&tNR,&temp),
											f.newIs(&dtZ,&dtemp)
									),
									f.newIs(&tNR,&tips)
							)
					)
			);

	//defuzzification
	Expression<double> *system = f.newDefuzz(&tips, r, 0.0, 20.0, 1.0);


	//apply input
	float s;
	while(true)
	{
		std::cout << "service : ";
		std::cin >> s;
		dtemp.setValue(s);
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
