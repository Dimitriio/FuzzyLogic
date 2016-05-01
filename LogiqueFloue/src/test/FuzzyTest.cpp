//============================================================================
// Name        : FuzzyTest.cpp
// Author      : Dimitri Reynié
// Version     :
// Copyright   : Your copyright notice
// Description : FuzzyTest in C++, Ansi-style
//============================================================================

#include <cassert>
#include <iostream>
#include <vector>

#include "../core/BinaryExpressionModel.h"
#include "../core/Expression.h"
#include "../core/NullPtrException.h"
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
#include "../fuzzy/SugenoConclusion.h"
#include "../fuzzy/SugenoDefuzz.h"
#include "../fuzzy/SugenoThen.h"
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

void testNullptrException()
{
	core::ValueModel<float>* r = new core::ValueModel<float>(0.9f);
	fuzzy::AndMin<float>* am = new fuzzy::AndMin<float>();
	core::BinaryExpressionModel<float>* bem = new core::BinaryExpressionModel<float>(nullptr, r, am);
	try{
		bem->evaluate();
	} catch (const NullPtrException &e) {
		assert(true);
	}
	bem = new core::BinaryExpressionModel<float>(r, nullptr, am);
	try{
		bem->evaluate();
	} catch (const NullPtrException &e) {
		assert(true);
	}
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
					f.newThen(
							f.newOr(
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

void SugenoTest(){
	//operators
		using namespace core;
		using namespace fuzzy;

		NotMinus1<double> opNot;
		AndMin<double> opAnd;
		OrMax<double> opOr;
		AggMax<double> opAgg;
		SugenoThen<double> opThen;
		SugenoDefuzz<double> opDefuzz;

		std::vector<double> coeffs;
		coeffs.push_back(1);
		coeffs.push_back(1);
		coeffs.push_back(1);

		SugenoConclusion<double> opConclusion(coeffs);
		//fuzzy expression factory
		FuzzyExpressionFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz, &opConclusion);

		//membership function
		IsCumulativeGaussian<double> poor(2.5,1.5,5);
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


		std::vector<core::Expression<double>*> rules;

		std::vector<core::Expression<double>*> sf;
		sf.push_back(&service);
		sf.push_back(&food);

		std::vector<core::Expression<double>*> serv;
		serv.push_back(&service);

		rules.push_back(
				f.newThen(
							f.newOr(
								f.newIs(&poor, &service),
								f.newIs(&rancid, &food)
							),
							f.newConclusion(&sf)
						));

		rules.push_back(
				f.newThen(
						f.newIs(&good, &service),
						f.newConclusion(&serv)
						));

		rules.push_back(
				f.newThen(
							f.newOr(
								f.newIs(&excellent, &service),
								f.newIs(&delicious, &food)
							),
							f.newConclusion(&sf)
						));

		//defuzzification
		Expression<double> *system = f.newSugeno(&rules);


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

void GestionPassage(){
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

	// Initial parameters;
	double time = 200; // in minutes
	double nbGroup = 10;


	//Trapeze TS
	IsTriangle<double> lowTS(10, 15, 20);
	IsTriangle<double> normalTS(15, 20, 25);
	IsTriangle<double> highTS(20, 25, 30);

	//membership function time
	IsTriangle<double> lowTL(150, 200, 250);
	IsTriangle<double> normalTL(150, 200, 250);
	IsTriangle<double> highTL(200,250, 300);


	IsTriangle<double> reduce(0,10,20);
	IsTriangle<double> doNothing(10, 20, 30);
	IsTriangle<double> increase(20,30,40);

	//values

	ValueModel<double> timeSpent(0.0);
	ValueModel<double> timeLeft(200);
	ValueModel<double> nextTime(0.0);

	Expression<double> *r =
						f.newAgg(
								f.newAgg(
										f.newThen(
												f.newIs(&lowTS, &timeSpent),
												f.newIs(&increase, &nextTime)
										),
										f.newThen(
												f.newIs(&highTS, &timeSpent),
												f.newIs(&reduce, &nextTime)
										)
								),
								f.newThen(
										f.newIs(&normalTS, &timeSpent),
										f.newIs(&doNothing, &nextTime)
								)
						);
			/*f.newAgg(
					f.newAgg(
							f.newAgg(
									f.newAgg(
											f.newAgg(
													f.newAgg(
															f.newAgg(
																	f.newAgg(
																			f.newThen(
																					f.newOr(
																						f.newIs(&lowTS, &timeSpent),
																						f.newIs(&highTL, &timeLeft)
																					),
																					f.newIs(&increase, &nextTime)
																			),
																			f.newThen(
																					f.newOr(
																						f.newIs(&normalTS, &timeSpent),
																						f.newIs(&normalTL, &timeLeft)
																					),
																					f.newIs(&doNothing, &nextTime)
																			)
																	),
																	f.newThen(
																			f.newOr(
																				f.newIs(&highTS, &timeSpent),
																				f.newIs(&lowTL, &timeLeft)
																			),
																			f.newIs(&reduce, &nextTime)
																	)
															),
															f.newThen(
																	f.newOr(
																		f.newIs(&lowTS, &timeSpent),
																		f.newIs(&lowTL, &timeLeft)
																	),
																	f.newIs(&doNothing, &nextTime)
															)
													),
													f.newThen(
															f.newOr(
																f.newIs(&highTS, &timeSpent),
																f.newIs(&highTL, &timeLeft)
															),
															f.newIs(&doNothing, &nextTime)
													)
											),
											f.newThen(
													f.newOr(
														f.newIs(&highTS, &timeSpent),
														f.newIs(&normalTL, &timeLeft)
													),
													f.newIs(&reduce, &nextTime)
											)
									),
									f.newThen(
											f.newOr(
												f.newIs(&normalTS, &timeSpent),
												f.newIs(&lowTL, &timeLeft)
											),
											f.newIs(&reduce, &nextTime)
									)
							),
							f.newThen(
									f.newOr(
										f.newIs(&lowTS, &timeSpent),
										f.newIs(&normalTL, &timeLeft)
									),
									f.newIs(&increase, &nextTime)
							)
					),
					f.newThen(
							f.newOr(
								f.newIs(&normalTS, &timeSpent),
								f.newIs(&highTL, &timeLeft)
							),
							f.newIs(&increase, &nextTime)
					)
			);*/

	//defuzzification
	Expression<double> *system = f.newDefuzz(&nextTime, r, 0.0, 30, 0.5);


	//apply input
	float s;
	while(true)
	{
		std::cout << "timeSpend : ";
		std::cin >> s;
		timeSpent.setValue(s);
		std::cout << "nextTime -> " << system->evaluate() << std::endl;
	}
}
int main() {
	//testValueModel();
	//testAndMin();
	//testAndMult();
	//testOrMax();
	//testOrPlus();
	//testThenMin();
	//testThenMult();
	//testAggMax();
	//testAggPlus();
	//testNotMinus1();
	//testIsTriangle();
	//testNullptrException();
	//factoryTest();
	//SugenoTest();
	GestionPassage();
	return 0;
}
