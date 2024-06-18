#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
uniform vec3 userColor;
uniform vec3 lightColor;
uniform sampler2D userTex;

void main()
{
	FragColor =  mix(texture(userTex, texCoord), vec4(userColor * lightColor,1.f), userColor.z);
}