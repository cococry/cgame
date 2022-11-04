#pragma once

#include <GLFW/glfw3.h>

typedef struct glfw_keyboard {
	bool8* active_keys;
	bool8* changed_keys;
} glfw_keyboard;

typedef struct glfw_mouse {
	bool8* active_buttons;
	bool8* changed_buttons;

	double xpos, ypos;
	double x_scroll_delta, y_scroll_delta;
	double xpos_last, ypos_last;
	double xpos_delta, ypos_delta;

	bool8 first_mouse;
} glfw_mouse;

typedef struct input_state {
	glfw_keyboard keyboard;
	glfw_mouse mouse;
} input_state;

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void glfw_button_callback(GLFWwindow* window, int button, int action, int mods);

void glfw_scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void glfw_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

void init_input();

void shutdown_input();

bool8 is_key_pressed(u32 key);

bool8 is_key_released(u32 key);

bool8 key_went_down(u32 key);

bool8 key_changed(u32 key);

bool8 is_mouse_button_pressed(u32 button);

bool8 is_mouse_button_released(u32 button);

bool8 mouse_button_went_down(u32 button);

bool8 mouse_button_changed(u32 button);

double get_mouse_cursor_x();

double get_mouse_cursor_y();

double get_mouse_cursor_x_delta();

double get_mouse_cursor_y_delta();

double get_mouse_scroll_x_delta();

double get_mouse_scroll_y_delta();
