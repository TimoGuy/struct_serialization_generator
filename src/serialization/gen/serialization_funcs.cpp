#include "serialization_funcs.h"

#include "../../simple_serializable_struct.h"


// Basic concrete types.
template<>
void HAWSOO::hserial::dump(uint8_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::load(uint8_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<uint64_t>();
}

template<>
void HAWSOO::hserial::dump(int8_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::load(int8_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<int64_t>();
}

template<>
void HAWSOO::hserial::dump(uint16_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::load(uint16_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<uint64_t>();
}

template<>
void HAWSOO::hserial::dump(int16_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::load(int16_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<int64_t>();
}

template<>
void HAWSOO::hserial::dump(uint32_t const& data, Generic_data_node& gdn)
{
    
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::load(uint32_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<uint64_t>();
}

template<>
void HAWSOO::hserial::dump(int32_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::load(int32_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<int64_t>();
}

template<>
void HAWSOO::hserial::dump(uint64_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::load(uint64_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<uint64_t>();
}

template<>
void HAWSOO::hserial::dump(int64_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::load(int64_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<int64_t>();
}

template<>
void HAWSOO::hserial::dump(float_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::DOUBLE_FLOAT);
    gdn.node_data.write_data(static_cast<double_t>(data));
}

template<>
void HAWSOO::hserial::load(float_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<double_t>();
}

template<>
void HAWSOO::hserial::dump(double_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::DOUBLE_FLOAT);
    gdn.node_data.write_data(static_cast<double_t>(data));
}

template<>
void HAWSOO::hserial::load(double_t& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<double_t>();
}

template<>
void HAWSOO::hserial::dump(std::string const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::STRING);
    gdn.node_data.write_data(data);
}

template<>
void HAWSOO::hserial::load(std::string& data, Generic_data_node const& gdn)
{
    data = gdn.node_data.read_data<std::string>();
}


// Custom struct types.
template<>
void HAWSOO::hserial::dump(My_simple_pub_struct const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(3);
    dump(data.my_char, gdn.children.emplace("my_char", Generic_data_node{}).first->second);
    dump(data.some_thingy, gdn.children.emplace("some_thingy", Generic_data_node{}).first->second);
    dump(data.my_theory, gdn.children.emplace("my_theory", Generic_data_node{}).first->second);
}

template<>
void HAWSOO::hserial::load(My_simple_pub_struct& data, Generic_data_node const& gdn)
{
    assert(gdn.node_data.get_type() == Generic_data::NODE_OBJECT);

    load(data.my_char, gdn.children.at("my_char"));
    load(data.some_thingy, gdn.children.at("some_thingy"));
    load(data.my_theory, gdn.children.at("my_theory"));
}

template<>
void HAWSOO::hserial::dump(Ok_ok_ima_stop_playin const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(2);
    dump(data.list_of_indexes, gdn.children.emplace("list_of_indexes", Generic_data_node{}).first->second);
    dump(data.three_strs, gdn.children.emplace("three_strs", Generic_data_node{}).first->second);
}

template<>
void HAWSOO::hserial::load(Ok_ok_ima_stop_playin& data, Generic_data_node const& gdn)
{
    assert(gdn.node_data.get_type() == Generic_data::NODE_OBJECT);

    load(data.list_of_indexes, gdn.children.at("list_of_indexes"));
    load(data.three_strs, gdn.children.at("three_strs"));
}
