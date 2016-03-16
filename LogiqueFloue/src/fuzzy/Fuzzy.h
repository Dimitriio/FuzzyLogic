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

typedef AggMax<NUMBER> 	_AggMax;
typedef AggPlus<NUMBER> _AggPlus;
typedef AndMin<NUMBER> _AndMin;
typedef CogDefuzz<NUMBER> _CogDefuzz;
typedef FuzzyExpressionFactory<NUMBER> _FuzzyExpressionFactory;
typedef IsCumulativeGaussian<NUMBER> _IsCumulativeGaussian;
typedef IsGaussian<NUMBER> _IsGaussian;
typedef IsTrapeze<NUMBER> _IsTrapeze;
typedef IsTriangle<NUMBER> _IsTriangle;
typedef MandaniDefuzz<NUMBER> _MandaniDefuzz;
typedef NotMinus1<NUMBER> _NotMinus1;
typedef OrMax<NUMBER> _OrMax;
typedef OrPlus<NUMBER> _OrPlus;
typedef ThenMin<NUMBER> _ThenMin;
typedef ThenMult<NUMBER> _ThenMult;

#endif /* FUZZY_FUZZY_H_ */
