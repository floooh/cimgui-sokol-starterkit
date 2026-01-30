//------------------------------------------------------------------------------
//  Simple C99 cimgui+sokol starter project for Win32, Linux and macOS.
//------------------------------------------------------------------------------
#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "imgui.h"
#include "sokol_imgui.h"

static struct {
    sg_pass_action pass_action;
} state;

static void init(void) {
    const sg_desc sgdesc = { .environment = sglue_environment(), .logger = { .func = slog_func } };
    sg_setup(sgdesc);
    const simgui_desc_t sidesc = { .logger = { .func = slog_func } };
    simgui_setup(sidesc);

    // initial clear color
    state.pass_action = (sg_pass_action) {
        .colors[0] = { .load_action = SG_LOADACTION_CLEAR, .clear_value = { 0.0f, 0.5f, 1.0f, 1.0 } }
    };
}

static void frame(void) {
    const simgui_frame_desc_t frame_desc = {
        .width = sapp_width(),
        .height = sapp_height(),
        .delta_time = sapp_frame_duration(),
        .dpi_scale = sapp_dpi_scale(),
    };
    simgui_new_frame(frame_desc);

    /*=== UI CODE STARTS HERE ===*/
    ImGui::SetNextWindowPos({10,10}, ImGuiCond_Once);
    ImGui::SetNextWindowSize((ImVec2){400, 100}, ImGuiCond_Once);
    ImGui::Begin("Hello Dear ImGui!", 0, ImGuiWindowFlags_None);
    ImGui::ColorEdit3("Background", &state.pass_action.colors[0].clear_value.r, ImGuiColorEditFlags_None);
    ImGui::End();
    /*=== UI CODE ENDS HERE ===*/

    const sg_pass pass = { .action = state.pass_action, .swapchain = sglue_swapchain() };
    sg_begin_pass(pass);
    simgui_render();
    sg_end_pass();
    sg_commit();
}

static void cleanup(void) {
    simgui_shutdown();
    sg_shutdown();
}

static void event(const sapp_event* ev) {
    simgui_handle_event(ev);
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    return {
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = event,
        .window_title = "Hello Sokol + Dear ImGui",
        .width = 800,
        .height = 600,
        .icon.sokol_default = true,
        .logger.func = slog_func,
    };
}
