#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 vertexColor;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vertexColor = vec4(aPos.x + 0.5f, aPos.y + 0.3f, aPos.z + 0.3f,0);
}