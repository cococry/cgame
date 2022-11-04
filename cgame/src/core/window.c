#include "pch.h"
#include "window.h"
#include "input.h"

#include <glad/glad.h>

void init_windowing(){
	ASSERT_MSG(glfwInit(), "Failed to initialize GLFW.");
}

void terminate_windowing(){
	glfwTerminate();
} 

window create_window(window_properties props) {
	window ret = { props, nullptr };

	glfwWindowHint(GLFW_RESIZABLE, props.resizable);

	ret.glfw_handle = glfwCreateWindow(ret.props.width, ret.props.height, ret.props.title, props.start_fullscreened ? glfwGetPrimaryMonitor() : nullptr, nullptr);

	glfwMakeContextCurrent(ret.glfw_handle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_ERROR("Failed to initialize Glad.");
	}

	glfwSetKeyCallback(ret.glfw_handle, glfw_key_callback);
	glfwSetMouseButtonCallback(ret.glfw_handle, glfw_button_callback);
	glfwSetCursorPosCallback(ret.glfw_handle, glfw_cursor_pos_callback);
	glfwSetScrollCallback(ret.glfw_handle, glfw_scroll_callback);
	glfwSetWindowPos(ret.glfw_handle, props.xpos, props.ypos);

	glfwSwapInterval(props.vsync);

	return ret;
}

void destroy_window(window* wnd){
	glfwDestroyWindow(wnd->glfw_handle);
}

void update_window(window* wnd) {
	glfwPollEvents();
	glfwSwapBuffers(wnd->glfw_handle);
}

bool8 window_is_open(window* wnd){
	return !glfwWindowShouldClose(wnd->glfw_handle);
}

void set_window_width(window* wnd, u32 width){
	glfwSetWindowSize(wnd->glfw_handle, width, wnd->props.height);
	wnd->props.width = width;
}

void set_window_height(window* wnd, u32 height){
	glfwSetWindowSize(wnd->glfw_handle, wnd->props.width, height);
	wnd->props.height = height;
}

void set_window_size(window* wnd, u32 width, u32 height){
	glfwSetWindowSize(wnd->glfw_handle, width, height);
	wnd->props.width = width;
	wnd->props.height = height;
}

void set_window_xpos(window* wnd, u32 xpos){
	glfwSetWindowPos(wnd->glfw_handle, xpos, wnd->props.ypos);
	wnd->props.xpos = xpos;
}

void set_window_ypos(window* wnd, u32 ypos){
	glfwSetWindowPos(wnd->glfw_handle, wnd->props.xpos, ypos);
	wnd->props.ypos = ypos;
}

void set_window_pos(window* wnd, u32 xpos, u32 ypos){
	glfwSetWindowPos(wnd->glfw_handle, xpos, ypos);
	wnd->props.xpos = xpos;
	wnd->props.ypos = ypos;
}

void set_window_title(window* wnd, const char* title){
	glfwSetWindowTitle(wnd->glfw_handle, title);
	wnd->props.title = title;
}