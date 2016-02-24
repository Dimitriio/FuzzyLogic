/*
 * MandaniDefuzz.h
 *
 *  Created on: 24 f�vr. 2016
 *      Author: Szymanski
 */

#ifndef FUZZY_MANDANIDEFUZZ_H_
#define FUZZY_MANDANIDEFUZZ_H_

#include "../core/BinaryExpression.h"

namespace fuzzy
{

template <class T>
class MandaniDefuzz : core::BinaryExpression<T>
{
public:
	MandaniDefuzz(const T&, const T&, const T&);
	virtual ~MandaniDefuzz() {};

	T evaluate(Expression<T>*, Expression<T>*) const;

	virtual T defuzz() const = 0;

private:

	T min, max, step, current;
};





#endif /* FUZZY_MANDANIDEFUZZ_H_ */
