#pragma once

#include "../generic_data_type.h"


namespace HAWSOO
{
namespace hserial
{

// Generic funcs.
template<class T>
void dump(T const& data, Generic_data_node& gdn)
{
    std::cerr << "ERROR: Type \"" << typeid(T).name()
              << "\" does not have a `dump()` func defined" << std::endl;
    assert(false);
}

template<class T>
void load(Generic_data_node const& gdn, T& data)
{
    std::cerr << "ERROR: Type \"" << typeid(T).name()
              << "\" does not have a `load()` func defined" << std::endl;
    assert(false);
}




}  // namespace hserial
}  // namespace HAWSOO