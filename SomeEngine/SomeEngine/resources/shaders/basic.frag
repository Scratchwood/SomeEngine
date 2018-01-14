#version 330 core

out vec4 outColor;
  
in DATA
{
	vec3 color;
	vec2 texCoords;
} fs_in;

uniform sampler2D texture;

void main()
{
    outColor = vec4(fs_in.color, 1.0);
}