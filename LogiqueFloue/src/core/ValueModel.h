#ifndef VALUEMODEL_H
#define VALUEMODEL_H

#include "Expression.h"

namespace core
{
	template<class T>
	class ValueModel : public Expression<T>
	{
	public:
		ValueModel(const T&);
		ValueModel(const Expression<T>*);
		virtual ~ValueModel();
		virtual void setValue(const T&);
		virtual T evaluate() const;

	private:
		T value;
	};

	template<class T>
	ValueModel<T>::ValueModel(const T& _value):
		value(_value)
	{
	}

	template<class T>
	ValueModel<T>::ValueModel(const Expression<T>* exp):
		value(exp->evaluate())
	{
	}

	template<class T>
	ValueModel<T>::~ValueModel()
	{
	}

	template<class T>
	void ValueModel<T>::setValue(const T& _value)
	{
		value = _value;
	}

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}
}
#endif
