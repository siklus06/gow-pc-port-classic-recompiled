#pragma once
#include <cstdint>

namespace gow_pc_port_classic_recompil {
inline constexpr const char* kModuleName = "gow-pc-port-classic-recompiled";
inline constexpr const char* kBuildSalt = "bea5da3c54b2f1d7";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace gow_pc_port_classic_recompil
