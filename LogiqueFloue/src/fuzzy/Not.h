/*
 * Not.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_NOT_NOT_H_
#define FUZZY_NOT_NOT_H_

namespace fuzzy
{
	template<class T>
	class Not : public core::UnaryExpression<T>
	{
	public:
		Not(){};
		virtual ~Not(){};

		virtual T evaluate(core::Expression<T>*) const;
	};

	template<class T>
	T  Not<T>::evaluate(core::Expression<T>* l) const
	{
	}
}

#endif /* FUZZY_NOT_NOT_H_ */
