#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 colorInfo;
layout (location = 2) in vec2 aTexCoord;


out vec4 vertexColor;
out vec2 texCoord;

uniform mat4 transform;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * transform;
	vertexColor = vec4(colorInfo, 1);
	texCoord = vec2(aTexCoord);
}