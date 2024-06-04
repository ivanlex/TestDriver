#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
uniform vec4 vertexColorLocation;

void main()
{
	FragColor = vec4(vertexColor.x * vertexColorLocation.x, vertexColor.y * vertexColorLocation.y, vertexColor.z * vertexColorLocation.z, 1);
}