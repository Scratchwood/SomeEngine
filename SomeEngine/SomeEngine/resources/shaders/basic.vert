#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;
layout (location = 2) in vec3 normal;
layout (location = 3) in vec3 color;


out DATA
{
	vec3 color;
	vec2 texCoords;
} vs_out;

void main()
{
    gl_Position = vec4(position, 1.0);
    vs_out.color = color;
    vs_out.texCoords = texCoords;
}