#include "serialization_funcs.h"

#include "../../simple_serializable_struct.h"



template<>
void HAWSOO::hserial::dump(uint8_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::dump(int8_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::dump(uint16_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::dump(int16_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::dump(uint32_t const& data, Generic_data_node& gdn)
{
    
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::dump(int32_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::dump(uint64_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::UNSIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<uint64_t>(data));
}

template<>
void HAWSOO::hserial::dump(int64_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::SIGNED_INTEGER);
    gdn.node_data.write_data(static_cast<int64_t>(data));
}

template<>
void HAWSOO::hserial::dump(float_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::DOUBLE_FLOAT);
    gdn.node_data.write_data(static_cast<double_t>(data));
}

template<>
void HAWSOO::hserial::dump(double_t const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::DOUBLE_FLOAT);
    gdn.node_data.write_data(static_cast<double_t>(data));
}

template<>
void HAWSOO::hserial::dump(std::string const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::STRING);
    gdn.node_data.write_data(data);
}


template<>
void HAWSOO::hserial::dump(My_simple_pub_struct const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(3);
    dump(data.my_char, gdn.children.emplace("my_char").first->second);
    dump(data.some_thingy, gdn.children.emplace("some_thingy").first->second);
    dump(data.my_theory, gdn.children.emplace("my_theory").first->second);
}

template<>
void HAWSOO::hserial::dump(Ok_ok_ima_stop_playin const& data, Generic_data_node& gdn)
{
    gdn.node_data.set_type(Generic_data::NODE_OBJECT);

    gdn.children.reserve(2);
    dump(data.list_of_indexes, gdn.children.emplace("list_of_indexes").first->second);
    dump(data.three_strs, gdn.children.emplace("three_strs").first->second);
}
