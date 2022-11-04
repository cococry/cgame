#include "pch.h"
#include "input.h"

static input_state s_state;

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action != GLFW_RELEASE) {
		if (!s_state.keyboard.active_keys[key]) {
			s_state.keyboard.active_keys[key] = true;
		}
	} else {
		s_state.keyboard.active_keys[key] = false;
	}
	s_state.keyboard.changed_keys[key] = (action != GLFW_REPEAT);
}

void glfw_button_callback(GLFWwindow* window, int button, int action, int mods) {
	if (action != GLFW_RELEASE) {
		if (!s_state.mouse.active_buttons[button]) {
			s_state.mouse.active_buttons[button] = true;
		}
	} else {
		s_state.mouse.active_buttons[button] = false;
	}
	s_state.mouse.changed_buttons[button] = (action != GLFW_REPEAT);
}

void glfw_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	s_state.mouse.x_scroll_delta = xoffset;
	s_state.mouse.y_scroll_delta = yoffset;
}

void glfw_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
	s_state.mouse.xpos = xpos;
	s_state.mouse.ypos = ypos;

	if (s_state.mouse.first_mouse) {
		s_state.mouse.xpos_last = xpos;
		s_state.mouse.ypos_last = xpos;
		s_state.mouse.first_mouse = false;
	}

	s_state.mouse.xpos_delta = s_state.mouse.xpos - s_state.mouse.xpos_last;
	s_state.mouse.ypos_delta = s_state.mouse.ypos - s_state.mouse.ypos_last;
	s_state.mouse.xpos_last = xpos;
	s_state.mouse.ypos_last = ypos;
}

void init_input() {
	// keyboard
	s_state.keyboard.active_keys = malloc(sizeof(bool8) * GLFW_KEY_LAST);
	s_state.keyboard.changed_keys = malloc(sizeof(bool8) * GLFW_KEY_LAST);
	if (s_state.keyboard.active_keys) {
		memset(s_state.keyboard.active_keys, 0, sizeof(bool8) * GLFW_KEY_LAST);
	} if (s_state.keyboard.changed_keys) {
		memset(s_state.keyboard.changed_keys, 0, sizeof(bool8) * GLFW_KEY_LAST);
	}
	s_state.mouse.active_buttons = malloc(sizeof(bool8) * GLFW_MOUSE_BUTTON_LAST);
	s_state.mouse.changed_buttons = malloc(sizeof(bool8) * GLFW_MOUSE_BUTTON_LAST);

	// mouse
	if (s_state.mouse.active_buttons) {
		memset(s_state.mouse.active_buttons, 0, sizeof(bool8) * GLFW_MOUSE_BUTTON_LAST);
	} if (s_state.mouse.changed_buttons) {
		memset(s_state.mouse.changed_buttons, 0, sizeof(bool8) * GLFW_MOUSE_BUTTON_LAST);
	}
	s_state.mouse.xpos = 0;
	s_state.mouse.ypos = 0;
	s_state.mouse.x_scroll_delta = 0;
	s_state.mouse.y_scroll_delta = 0;
	s_state.mouse.xpos_last = 0;
	s_state.mouse.ypos_last = 0;
	s_state.mouse.xpos_delta = 0;
	s_state.mouse.ypos_delta = 0;
	s_state.mouse.first_mouse = true;
}

void shutdown_input() {
	free(s_state.keyboard.active_keys);
	free(s_state.keyboard.changed_keys);
}

bool8 is_key_pressed(u32 key) {
	return s_state.keyboard.active_keys[key];
}

bool8 is_key_released(u32 key) {
	return key_changed(key) && !s_state.keyboard.active_keys[key];
}

bool8 key_went_down(u32 key) {
	return key_changed(key) && s_state.keyboard.active_keys[key];
}

bool8 key_changed(u32 key) {
	bool8 ret = s_state.keyboard.changed_keys[key];
	s_state.keyboard.changed_keys[key] = false;
	return ret;
}

bool8 is_mouse_button_pressed(u32 button) {
	return s_state.mouse.active_buttons[button];
}

bool8 is_mouse_button_released(u32 button) {
	return mouse_button_changed(button) && !s_state.mouse.active_buttons[button];
}

bool8 mouse_button_went_down(u32 button) {
	return mouse_button_changed(button) && s_state.mouse.active_buttons[button];
}

bool8 mouse_button_changed(u32 button) {
	bool8 ret = s_state.mouse.changed_buttons[button];
	s_state.mouse.changed_buttons[button] = false;
	return ret;
}

double get_mouse_cursor_x() {
	return s_state.mouse.xpos;
}

double get_mouse_cursor_y() {
	return s_state.mouse.ypos;
}

double get_mouse_cursor_x_delta() {
	return s_state.mouse.xpos_delta;
}

double get_mouse_cursor_y_delta() {
	return s_state.mouse.ypos_delta;
}

double get_mouse_scroll_x_delta() {
	return s_state.mouse.x_scroll_delta;
}

double get_mouse_scroll_y_delta() {
	return s_state.mouse.y_scroll_delta;
}
