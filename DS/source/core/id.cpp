#include "id.hpp"

namespace DS
{
    uint64_t UUID::s_lastID = 0;

    UUID::UUID()
    {
        m_id = s_lastID++;
    }

}