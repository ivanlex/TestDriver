#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
uniform vec3 userColor;
uniform sampler2D userTex;

void main()
{
	vec4 tempColor = vec4(vertexColor.x + userColor.x, vertexColor.y + userColor.y, vertexColor.z + userColor.z, 1.f);
	FragColor = texture(userTex, texCoord) * tempColor;
}