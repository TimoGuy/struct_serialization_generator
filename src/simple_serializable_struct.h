#pragma once

#include <cstdint>
#include <string>


namespace HAWSOO
{

/// @HAWSOO_SERIALIZE[public].
struct My_simple_pub_struct
{
    char my_char;
    uint32_t some_thingy;
    std::string my_theory;

private:
    std::string i_have_a_private_str;
};

/// @HAWSOO_SERIALIZE[public].
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

}  // namespace HAWSOO