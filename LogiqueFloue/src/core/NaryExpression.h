/*
 * NaryExpression.h
 *
 *  Created on: 16 mars 2016
 *      Author: Dimitri
 */

#ifndef CORE_NARYEXPRESSION_H_
#define CORE_NARYEXPRESSION_H_

namespace core {
	template<class T>
	class NaryExpression {
	public:
		virtual ~NaryExpression();

		virtual T evaluate(Expression<T>**) const =0;
	};
}

#endif /* CORE_NARYEXPRESSION_H_ */
