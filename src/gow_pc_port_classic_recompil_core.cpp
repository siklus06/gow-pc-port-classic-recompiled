#include "../include/gow_pc_port_classic_recompil_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace gow_pc_port_classic_recompil {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace gow_pc_port_classic_recompil

int main() {
    bool menu_open = true;
    while (gow_pc_port_classic_recompil::g_running.load(std::memory_order_relaxed)) {
        gow_pc_port_classic_recompil::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}
