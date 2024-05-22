#ifndef DS_COMMON_HPP
#define DS_COMMON_HPP

#define GETTER(type, name, var) inline type name() {return var;}
#define CGETTER(type, name, var) inline type name() const {return var;}

#endif