#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
uniform float transparent;

void main()
{
	FragColor = vec4(vertexColor.x, vertexColor.y, vertexColor.z, 0.2f * transparent);
}