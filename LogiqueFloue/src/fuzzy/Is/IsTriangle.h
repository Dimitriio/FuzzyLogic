/*
 * IsTriangle.h
 *
 *  Created on: 27 janv. 2016
 *      Author: Dimitri
 */

#ifndef FUZZY_IS_ISTRIANGLE_H_
#define FUZZY_IS_ISTRIANGLE_H_

#include "../../core/Expression.h"
#include "Is.h"

namespace fuzzy
{
	template<class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle(const T&,const T&,const T&);
		virtual ~IsTriangle(){};

		virtual T evaluate(core::Expression<T>*) const;

	private:
		T min, mid, max;
	};

	template<class T>
	IsTriangle<T>::IsTriangle(const T& _min,const T& _mid, const T& _max):
	min(_min),mid(_mid),max(_max)
	{
	}

	template<class T>
	T IsTriangle<T>::evaluate(core::Expression<T>* l) const
	{
		if(l->evaluate()<min || l->evaluate()>max)
			return 0;
		else if(l->evaluate()<(min+max)/2)
			return mid/((min+max)/2-min)*(l->evaluate()-min);
		return -mid/(max-(min+max)/2)*(l->evaluate()-max);
	}
}

#endif /* FUZZY_IS_ISTRIANGLE_H_ */
