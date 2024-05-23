#ifndef DS_ID_HPP
#define DS_ID_HPP

#include "common.hpp"

namespace DS
{
    class UUID
    {
    public:
        UUID();
        ~UUID() = default;

        GETTER(uint64_t, to_uint64, m_id);

        inline operator int64_t() const { return m_id; }
        inline bool operator==(const UUID &rhs) const { return m_id == rhs.m_id; }

    private:
        uint64_t m_id;
        static uint64_t s_lastID;
    };
}

#endif