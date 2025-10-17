#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>


namespace HAWSOO
{

class Generic_data
{
public:
    enum Data_type
    {
        UNDEFINED,
        UNSIGNED_INTEGER,
        SIGNED_INTEGER,
        DOUBLE_FLOAT,
        STRING,
        NUM_DATA_TYPES
    };

    Generic_data()
        : m_type(UNDEFINED)
    {
    }

    explicit Generic_data(Data_type data_type)
        : m_type(data_type)
    {
        if (m_type == STRING)
        {
            m_data.data_str = nullptr;
        }
    }

    Generic_data(const Generic_data&)            = delete;
    Generic_data& operator=(const Generic_data&) = delete;
    Generic_data(Generic_data&&)                 = delete;
    Generic_data& operator=(Generic_data&&)      = delete;

    ~Generic_data()
    {
        if (m_type == STRING && m_data.data_str != nullptr)
        {
            delete m_data.data_str;
        }
    }

    // Read data funcs.
    template<typename T>
    T read_data()
    {
        std::cerr << "ERROR: Type \"" << typeid(T).name()
                  << "\" does not have a `read_data()` func defined" << std::endl;
        assert(false);
        return nullptr;
    }

    template<>
    uint64_t read_data()
    {
        assert(m_type == UNSIGNED_INTEGER);
        return m_data.data_u64;
    }

    template<>
    int64_t read_data()
    {
        assert(m_type == SIGNED_INTEGER);
        return m_data.data_i64;
    }

    template<>
    double_t read_data()
    {
        assert(m_type == DOUBLE_FLOAT);
        return m_data.data_dbl_flt;
    }

    template<>
    std::string read_data()
    {
        assert(m_type == STRING);
        return *m_data.data_str;
    }

    // Write data funcs.
    void write_data(uint64_t new_data)
    {
        assert(m_type == UNSIGNED_INTEGER);
        m_data.data_u64 = new_data;
    }

    void write_data(int64_t new_data)
    {
        assert(m_type == SIGNED_INTEGER);
        m_data.data_i64 = new_data;
    }

    void write_data(double_t new_data)
    {
        assert(m_type == DOUBLE_FLOAT);
        m_data.data_dbl_flt = new_data;
    }

    void write_data(std::string const& new_data)
    {
        assert(m_type == STRING);
        if (m_data.data_str != nullptr)
            delete m_data.data_str;
        m_data.data_str = new std::string(new_data);
    }

private:
    union Data_u
    {
        uint64_t     data_u64;
        int64_t      data_i64;
        double_t     data_dbl_flt;
        std::string* data_str;
    } m_data;

    Data_type m_type;
};

struct Generic_data_node
{
    Generic_data node_data;
    std::unordered_map<std::string, Generic_data_node> children;
};

}  // HAWSOO
