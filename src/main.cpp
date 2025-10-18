#include "serialization/gen/serialization_funcs.h"
#include "serialization/generic_data_type.h"
#include "simple_serializable_struct.h"

#include <cstdint>
#include <iostream>


int32_t main()
{
    using namespace HAWSOO;

    Ok_ok_ima_stop_playin inst;
    inst.list_of_indexes.emplace_back(1);
    inst.list_of_indexes.emplace_back(1);
    inst.list_of_indexes.emplace_back(3);
    inst.list_of_indexes.emplace_back(1);
    inst.list_of_indexes.emplace_back(2);
    inst.list_of_indexes.emplace_back(3);
    inst.list_of_indexes.emplace_back(4);
    inst.list_of_indexes.emplace_back(69);
    inst.three_strs[0] = "Ok here's str one!";
    inst.three_strs[1] = "Aaaand me! The second.";
    inst.three_strs[2] = "And then here we are, the 3 wise strs";

    Generic_data_node gdn;
    hserial::dump(inst, gdn);

    int ian{ 69 };

    Ok_ok_ima_stop_playin inst2;
    hserial::load(inst2, gdn);

    int ian2{ 69 };
    return 0;
}
