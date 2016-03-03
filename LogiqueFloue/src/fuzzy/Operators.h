/*
 * Agg.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_OPERATORS_H_
#define FUZZY_OPERATORS_H_

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"
#include "../core/UnaryExpression.h"

namespace fuzzy
{
	template<class T>
	class Agg : public core::BinaryExpression<T>
	{
	public:
		Agg(){};
		virtual ~Agg(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*)const = 0;
	};

	template<class T>
	class And : public core::BinaryExpression<T>
	{
	public:
		And(){};
		virtual ~And(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const = 0;
	};

	template<class T>
	class Is : public core::UnaryExpression<T>
	{
	public:
		Is(){};
		virtual ~Is(){};

		virtual T evaluate(core::Expression<T>*) const = 0;
	};

	template<class T>
	class Not : public core::UnaryExpression<T>
	{
	public:
		Not(){};
		virtual ~Not(){};

		virtual T evaluate(core::Expression<T>*) const = 0;
	};

	template<class T>
	class Or : public core::BinaryExpression<T>
	{
	public:
		Or(){};
		virtual ~Or(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const = 0;
	};

	template<class T>
	class Then : public core::BinaryExpression<T>
	{
	public:
		Then(){};
		virtual ~Then(){};

		virtual T evaluate(core::Expression<T>*,core::Expression<T>*) const = 0;
	};
}

#endif /* FUZZY_OPERATORS_H_ */
