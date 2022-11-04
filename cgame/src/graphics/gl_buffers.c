#include "pch.h"
#include "gl_buffers.h"

#include <glad/glad.h>

vertex_buffer vertex_buffer_create(float* vertices, u32 size, u32 draw_mode) {
	vertex_buffer vb = { 0 };
	glCreateBuffers(1, &vb.renderer_id);
	glBindBuffer(GL_ARRAY_BUFFER, vb.renderer_id);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, draw_mode);
	return vb;
}

void vertex_buffer_bind(vertex_buffer* buffer) {
	glBindBuffer(GL_ARRAY_BUFFER, buffer->renderer_id);
}

void vertex_buffer_unbind(vertex_buffer* buffer) {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void vertex_buffer_delete(vertex_buffer* buffer) {
	glDeleteBuffers(1, &buffer->renderer_id);
}

void vertex_buffer_set_data(vertex_buffer* buffer, float* vertices, u32 size, u32 offset) {
	glBindBuffer(GL_ARRAY_BUFFER, buffer->renderer_id);
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, vertices);
}


index_buffer index_buffer_create(u32* indices, u32 count, u32 draw_mode) {
	index_buffer ib = { 0 };
	glCreateBuffers(1, &ib.renderer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib.renderer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(u32), indices, draw_mode);
	return ib;
}

void index_buffer_bind(index_buffer* buffer) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer->renderer_id);
}

void index_buffer_unbind(index_buffer* buffer) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void index_buffer_delete(index_buffer* buffer) {
	glDeleteBuffers(1, &buffer->renderer_id);
}

