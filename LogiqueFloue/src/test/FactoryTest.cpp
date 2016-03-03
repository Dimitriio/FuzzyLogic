#include <iostream>

#include "../core/Expression.h"
#include "../core/ValueModel.h"
#include "../fuzzy/AggMax.h"
#include "../fuzzy/AndMin.h"
#include "../fuzzy/CogDefuzz.h"
#include "../fuzzy/FuzzyExpressionFactory.h"
#include "../fuzzy/IsTriangle.h"
#include "../fuzzy/NotMinus1.h"
#include "../fuzzy/OrMax.h"
#include "../fuzzy/ThenMin.h"

/*
 * FactoryTest.cpp
 *
 *  Created on: 2 mars 2016
 *      Author: Dimitri
 */


/*void factoryTest()
{
	//operators
	using namespace core;
	using namespace fuzzy;
	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	AggMax<double> opAgg;
	ThenMin<double> opThen;
	CogDefuzz<double> opDefuzz(0,25,1);

	//fuzzy expression factory
	FuzzyExpressionFactory<double> f(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opDefuzz);

	//membership function
	IsTriangle<double> poor(-5,0,5);
	IsTriangle<double> good(0,5,10);
	IsTriangle<double> excellent(5,10,15);

	IsTriangle<double> cheap(0,5,10);
	IsTriangle<double> average(10,15,20);
	IsTriangle<double> generous(20,25,30);

	//values

	ValueModel<double> service(0.0);
	ValueModel<double> food(0.0);
	ValueModel<double> tips(0.0);

	Expression<double> *r =
			f.newAgg(
					f.newAgg(
							f.newThen(
									f.newIs(&poor,&service),
									f.newIs(&cheap,&tips)
							),
							f.newThen(
									f.newIs(&good,&service),
									f.newIs(&average,&tips)
							)
					),
					f.newThen(
							f.newIs(&excellent,&service),
							f.newIs(&generous,&tips)
					)
			);

	//defuzzification
	Expression<double> *system = f.newDefuzz(&tips, r, 0, 25, 1);


	//apply input
	float s;
	while(true)
	{
		std::cout << "service : ";
		std::cin >> s;
		service.setValue(s);
		std::cout << "tips -> " << system->evaluate() << std::endl;
	}

}*/

