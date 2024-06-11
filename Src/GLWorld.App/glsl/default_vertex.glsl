#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;


out vec4 vertexColor;
out vec2 texCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 transform;

void main()
{
	gl_Position =  projection * view * transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);
	vertexColor = vec4(aPos, 1);
	texCoord = vec2(aTexCoord);
}