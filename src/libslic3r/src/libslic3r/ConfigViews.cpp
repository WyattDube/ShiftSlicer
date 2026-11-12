#include "libslic3r/ConfigViews.hpp"

using Slic3r::Domain::VirtualExtruder;

namespace Slic3r {

std::optional<unsigned int> PrintRegionConfigView::source_virtual_extruder() const
{
    if (m_virtual_extruders.empty()) {
        return std::nullopt;
    }

    for (const char* key : {"perimeter_extruder", "external_perimeter_extruder"}) {
        const unsigned int id =
            static_cast<unsigned int>(this->resolve_value(key).get<int>());

        for (const VirtualExtruder& virtual_extruder : m_virtual_extruders) {
            if (virtual_extruder.id == id) {
                return id;
            }
        }
    }

    return std::nullopt;
}

} // namespace Slic3r