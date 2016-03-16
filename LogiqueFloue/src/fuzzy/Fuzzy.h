/*
 * Fuzzy.h
 *
 *  Created on: 16 mars 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_FUZZY_H_
#define FUZZY_FUZZY_H_

#include "AggMax.h"
#include "AggPlus.h"
#include "AndMin.h"
#include "AndMult.h"
#include "CogDefuzz.h"
#include "FuzzyExpressionFactory.h"
#include "IsCumulativeGaussian.h"
#include "IsGaussian.h"
#include "IsTrapeze.h"
#include "IsTriangle.h"
#include "MamdaniDefuzz.h"
#include "NotMinus1.h"
#include "OrMax.h"
#include "OrPlus.h"
#include "ThenMin.h"
#include "ThenMult.h"

#define NUMBER double

using namespace fuzzy;

typedef AggMax<NUMBER> aggMax;
typedef AggPlus<NUMBER> aggPlus;
typedef AndMin<NUMBER> andMin;
typedef CogDefuzz<NUMBER> cogDefuzz;
typedef FuzzyExpressionFactory<NUMBER> fuzzyExpressionFactory;
typedef IsCumulativeGaussian<NUMBER> isCumulativeGaussian;
typedef IsGaussian<NUMBER> isGaussian;
typedef IsTrapeze<NUMBER> isTrapeze;
typedef IsTriangle<NUMBER> isTriangle;
typedef MandaniDefuzz<NUMBER> mandaniDefuzz;
typedef NotMinus1<NUMBER> notMinus1;
typedef OrMax<NUMBER> orMax;
typedef OrPlus<NUMBER> orPlus;
typedef ThenMin<NUMBER> thenMin;
typedef ThenMult<NUMBER> thenMult;

#endif /* FUZZY_FUZZY_H_ */
