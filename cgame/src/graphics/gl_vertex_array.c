#include "pch.h"
#include "gl_vertex_array.h"

#include <glad/glad.h>

vertex_array vertex_array_create() {
	vertex_array va = { 0, nullptr };
	glCreateVertexArrays(1, &va.renderer_id);
	glBindVertexArray(va.renderer_id);
	return va;
}

void vertex_array_bind(vertex_array* va) {
	glBindVertexArray(va->renderer_id);
}

void vertex_array_unbind(vertex_array* va) {
	glBindVertexArray(0);
}

void vertex_array_delete(vertex_array* va) {
	glDeleteVertexArrays(1, &va->renderer_id);
}

void vertex_array_set_index_buffer(vertex_array* va, index_buffer* buffer) {
	vertex_array_bind(va);
	index_buffer_bind(buffer);
	va->index_buffer = buffer;
}

void vertex_array_set_layout_attribute(vertex_array* va, u32 index, u32 element_count, u32 vertex_stride, u32 offset) {
	glVertexAttribPointer(index, element_count, GL_FLOAT, GL_FALSE, vertex_stride, (void*)(intptr_t)offset);
	glEnableVertexAttribArray(index);
}
