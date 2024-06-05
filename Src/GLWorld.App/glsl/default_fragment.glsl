#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
uniform sampler2D userTex;

void main()
{
	vec4 tempColor = vec4(vertexColor.x, vertexColor.y, vertexColor.z, 1.f);
	FragColor = texture(userTex, texCoord);
}