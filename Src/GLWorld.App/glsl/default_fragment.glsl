#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
uniform vec3 vertexColorParam;

void main()
{
	FragColor = vec4(vertexColor.x * vertexColorParam.x, vertexColor.y * vertexColorParam.y, vertexColor.z * vertexColorParam.z, 1.f);
}