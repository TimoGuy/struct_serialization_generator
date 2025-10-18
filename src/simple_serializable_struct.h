#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>


namespace HAWSOO
{

/// @HAWSOO_SERIALIZE.
struct My_simple_pub_struct
{
    char my_char;
    uint32_t some_thingy;
    std::string my_theory;

private:
    std::string i_have_a_private_str;
};

/// @HAWSOO_SERIALIZE.
class My_simple_pub_class
{
    char my_char;
    uint32_t some_thingy;
    std::string my_theory;

public:
    std::string i_have_a_public_str;
};

/// @HAWSOO_SERIALIZE.
class My_simple_priv_class
{
    int32_t num1;
    int32_t num2;
    int32_t num3;
    double_t num5;
    double_t num4;
};

/// @HAWSOO_SERIALIZE.
struct Ok_ok_ima_stop_playin
{
    std::vector<uint32_t> list_of_indexes;
    std::array<std::string, 3> three_strs;
};

/// @HAWSOO_SERIALIZE.
struct I_has_a_nested_struct
{
    int32_t jojo;
    float_t koko;

    struct Heres_the_nested_struct
    {
        std::string nest_str;
        size_t some_irregular_thingy;
    } nested_val;
};

}  // namespace HAWSOO