#pragma once

typedef struct vertex_buffer {
	render_id renderer_id;
} vertex_buffer;

typedef struct index_buffer {
	render_id renderer_id;
	u32 index_count;
} index_buffer;

vertex_buffer vertex_buffer_create(float* vertices, u32 size, u32 draw_mode);

void vertex_buffer_bind(vertex_buffer* buffer);

void vertex_buffer_unbind(vertex_buffer* buffer);

void vertex_buffer_delete(vertex_buffer* buffer);

void vertex_buffer_set_data(vertex_buffer* buffer, float* vertices, u32 size, u32 offset);

index_buffer index_buffer_create(u32* indices, u32 count, u32 draw_mode);

void index_buffer_bind(index_buffer* buffer);

void index_buffer_unbind(index_buffer* buffer);

void index_buffer_delete(index_buffer* buffer);

