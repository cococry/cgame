#include "pch.h"
#include "application.h"
#include "input.h"


#include <GLFW/glfw3.h>
#include <glad/glad.h>

application create_application(window_properties wnd_props) {
	init_windowing();
	application_state state = { 0.0f, 0.0f };
	application ret = {state, create_window(wnd_props)};

	init_input();

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f
	};
	u32 indices[] = { 0, 1, 2, 2, 3, 0 };

	ret.state.va = vertex_array_create();

	vertex_buffer vb = vertex_buffer_create(vertices, sizeof(vertices), GL_STATIC_DRAW);
	index_buffer ib = index_buffer_create(indices, sizeof(indices) / sizeof(u32), GL_STATIC_DRAW);

	vertex_array_set_index_buffer(&ret.state.va, &ib);

	vertex_array_set_layout_attribute(&ret.state.va, 0, 3, sizeof(float) * 3, 0);

	return ret;
}

void update_application(application* app) {
	while (window_is_open(&app->wnd)) {
		float currentFrameTime = (float)glfwGetTime();
		app->state.deltaTime = currentFrameTime - app->state.lastFrameTime;
		app->state.lastFrameTime = currentFrameTime;

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

		glDrawElements(GL_TRIANGLES, app->state.va.index_buffer->index_count, GL_UNSIGNED_INT, nullptr);

		update_window(&app->wnd);
	}
}

void shutdown_application(application* app) {
	destroy_window(&app->wnd);
	terminate_windowing();
	shutdown_input();
}
