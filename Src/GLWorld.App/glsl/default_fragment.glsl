#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
uniform vec3 userColor;
uniform vec3 lightColor;
uniform sampler2D userTex;
uniform sampler2D userTex2;

void main()
{


	// vec4 tempColor = vec4(vertexColor.x + userColor.x, vertexColor.y + userColor.y, vertexColor.z + userColor.z, 1.f);
	//vec4 tempColor = vec4(userColor.x, userColor.y, userColor.z, 1.f);
	//FragColor = mix(texture(userTex, texCoord), texture(userTex2, texCoord), userColor.z) * tempColor;
	FragColor =  mix(texture(userTex, texCoord), vec4(userColor * lightColor,1.f), userColor.z);
}