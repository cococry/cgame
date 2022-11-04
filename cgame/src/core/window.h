#pragma once

#include "core.h"

#include <GLFW/glfw3.h>

typedef struct window_properties {
	u32 width, height;
	u32 xpos, ypos;
	const char* title;
	bool8 resizable;
	bool8 vsync;
	bool8 start_fullscreened;
} window_properties;

typedef struct window {
	window_properties props;
	GLFWwindow* glfw_handle;
} window;

void init_windowing();

void terminate_windowing();

window create_window(window_properties props);

void destroy_window(window* wnd);

void update_window(window* wnd);

bool8 window_is_open(window* wnd);

void set_window_width(window* wnd, u32 width);

void set_window_height(window* wnd, u32 height);

void set_window_size(window* wnd, u32 width, u32 height);

void set_window_xpos(window* wnd, u32 xpos);

void set_window_ypos(window* wnd, u32 ypos);

void set_window_pos(window* wnd, u32 xpos, u32 ypos);

void set_window_title(window* wnd, const char* title);