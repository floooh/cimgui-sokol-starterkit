#include "App.h"

#include <stdlib.h>
#include <imgui/imgui.h>

struct App
{
	constexpr static auto WINDOW_TITLE = "App";
};

App*
app_new()
{
	return (App*)::malloc(sizeof(App));
}

const char*
app_title()
{
	return App::WINDOW_TITLE;
}

void
app_init(App* self)
{
}

void
app_dispose(App* self)
{
	::free(self);
}

void
app_frame(App* self)
{
	ImGui::SetNextWindowPos({10, 10}, ImGuiCond_Once);
	ImGui::SetNextWindowSize({400, 100}, ImGuiCond_Once);
    ImGui::Begin("Hello Dear ImGui!");
	ImGui::Text("Take off.");
    ImGui::End();
}