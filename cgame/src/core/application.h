#pragma once

#include "window.h"

#include "graphics/gl_vertex_array.h"

typedef struct application_state {
	float deltaTime;
	float lastFrameTime;
	vertex_array va;

} application_state;

typedef struct application {
	application_state state;
	window wnd;
} application;

application create_application(window_properties wnd_props);

void update_application(application* app);

void shutdown_application(application* app);