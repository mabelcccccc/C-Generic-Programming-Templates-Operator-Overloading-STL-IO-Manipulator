#ifndef MY_TEMPLATES_H
#define MY_TEMPLATES_H

#include <cmath>

template<typename T>
bool equals(T param1, T param2){
	return param1==param2;
}

template<typename T>
double scalar_difference(T param1, T param2){
     return fabs(param1.getScalarValue()-param2.getScalarValue());
}






#endif // MY_TEMPLATES_H
