#pragma once

#include "../generic_data_type.h"

#include <array>
#include <iostream>
#include <string>
#include <vector>



// Forward declarations.
namespace HAWSOO
{
struct My_simple_pub_struct;
struct Ok_ok_ima_stop_playin;
}
////////////////////////

namespace HAWSOO
{
namespace hserial
{

// Generic type.
template<class T>
void dump(T const& data, Generic_data_node& gdn)
{
    std::cerr << "ERROR: Type \"" << typeid(T).name()
              << "\" does not have a `dump()` func defined" << std::endl;
    assert(false);
}

template<class T>
void load(T& data, Generic_data_node const& gdn)
{
    std::cerr << "ERROR: Type \"" << typeid(T).name()
              << "\" does not have a `load()` func defined" << std::endl;
    assert(false);
}

// Generic std::vector.
template<class T>
void dump(std::vector<T> const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(data.size());
    for (size_t i = 0; i < data.size(); i++)
    {
        dump(data[i], gdn.children.emplace(std::to_string(i), Generic_data_node{}).first->second);
    }
}

template<class T>
void load(std::vector<T>& data, Generic_data_node const& gdn)
{
    assert(gdn.node_data.get_type() == Generic_data::NODE_OBJECT);

    data.resize(gdn.children.size());
    for (size_t i = 0; i < gdn.children.size(); i++)
    {
        load(data[i], gdn.children.at(std::to_string(i)));
    }
}

// Generic std::array.
template<class T, size_t N>
void dump(std::array<T, N> const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(data.size());
    for (size_t i = 0; i < data.size(); i++)
    {
        dump(data[i], gdn.children.emplace(std::to_string(i), Generic_data_node{}).first->second);
    }
}

template<class T, size_t N>
void load(std::array<T, N>& data, Generic_data_node const& gdn)
{
    assert(gdn.node_data.get_type() == Generic_data::NODE_OBJECT);

    for (size_t i = 0; i < gdn.children.size(); i++)
    {
        load(data[i], gdn.children.at(std::to_string(i)));
    }
}

// Basic concrete types.
template<> void dump(uint8_t const& data, Generic_data_node& gdn);
template<> void load(uint8_t& data, Generic_data_node const& gdn);
template<> void dump(int8_t const& data, Generic_data_node& gdn);
template<> void load(int8_t& data, Generic_data_node const& gdn);
template<> void dump(uint16_t const& data, Generic_data_node& gdn);
template<> void load(uint16_t& data, Generic_data_node const& gdn);
template<> void dump(int16_t const& data, Generic_data_node& gdn);
template<> void load(int16_t& data, Generic_data_node const& gdn);
template<> void dump(uint32_t const& data, Generic_data_node& gdn);
template<> void load(uint32_t& data, Generic_data_node const& gdn);
template<> void dump(int32_t const& data, Generic_data_node& gdn);
template<> void load(int32_t& data, Generic_data_node const& gdn);
template<> void dump(uint64_t const& data, Generic_data_node& gdn);
template<> void load(uint64_t& data, Generic_data_node const& gdn);
template<> void dump(int64_t const& data, Generic_data_node& gdn);
template<> void load(int64_t& data, Generic_data_node const& gdn);
template<> void dump(float_t const& data, Generic_data_node& gdn);
template<> void load(float_t& data, Generic_data_node const& gdn);
template<> void dump(double_t const& data, Generic_data_node& gdn);
template<> void load(double_t& data, Generic_data_node const& gdn);
template<> void dump(std::string const& data, Generic_data_node& gdn);
template<> void load(std::string& data, Generic_data_node const& gdn);

// Custom struct types.
template<> void dump(My_simple_pub_struct const& data, Generic_data_node& gdn);
template<> void load(My_simple_pub_struct& data, Generic_data_node const& gdn);
template<> void dump(Ok_ok_ima_stop_playin const& data, Generic_data_node& gdn);
template<> void load(Ok_ok_ima_stop_playin& data, Generic_data_node const& gdn);


}  // namespace hserial
}  // namespace HAWSOO