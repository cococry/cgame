#pragma once

#include "gl_buffers.h"

typedef struct vertex_array {
	render_id renderer_id;
	index_buffer* index_buffer;
} vertex_array;

vertex_array vertex_array_create();

void vertex_array_bind(vertex_array* va);

void vertex_array_unbind(vertex_array* va);

void vertex_array_delete(vertex_array* va);

void vertex_array_set_index_buffer(vertex_array* va, index_buffer* buffer);

void vertex_array_set_layout_attribute(vertex_array* va, u32 index, u32 element_count, u32 vertex_stride, u32 offset);
