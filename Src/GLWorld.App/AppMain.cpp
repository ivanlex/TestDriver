#include "common/common_def.h"
#include "shader/Shader.h"
#include "texture/Texture.h"

float vertices[] = {
	// first triangle    //color			//tex
	0.5f, 0.5f, 0.0f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f, // top right
	0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,	0.0f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f,	1.0f, 1.0f, 0.0f,	0.0f, 1.0f // top left
};

float vertices2[] = {
	// first triangle   //color
	0.5f, 0.1f, 0.0f,   1.f, 0,  0,
	0.5f, -0.5f, 0.0f,  0,  1.f, 0,
	-0.5f, 0.5f, 0.0f,  0,   0, 1.f,
	-0.5f, 0.5f, 0.0f,  0,   0, 1.f
};

float params[] = {
	1.2f, 2.3f
};

GLuint indices[] = {
	0, 1, 3, // first triangle
	1, 2, 3,  // second triangle
};

int main()
{
	if (!glfwInit())
	{
		LOG("Glfw init failed");
	}

	GLFWwindow* window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,
		WINDOW_DEFAULT_HEIGHT,
		APP_TITLE,
		NULL,
		NULL
	);

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);
	setCallbacks(window);
	glClearColor(0.f, 0.f, 0.f, 1.f);

	Shader defaultShader(DEFAULT_VERTEX, DEFAULT_FRAGMENT);
	Texture defaultTexture(DEFAULT_TEXTURE);
	Texture secondTexture(SECOND_TEXTURE);

	GLuint vbo, vao, ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	int stride[] = {3,3,2};

	for (int i = 0; i < 3; i++)
	{
		glVertexAttribPointer(
			i, 
			stride[i],
			GL_FLOAT,
			GL_FALSE,
			8 * sizeof(GL_FLOAT),
			(void*)(i * (i  > 0 ? stride[i-1] : 0) * sizeof(float))
		);
		glEnableVertexAttribArray(i);
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
	defaultShader.use();
	
	glBindVertexArray(vao);
	
	defaultTexture.use(GL_TEXTURE0);
	secondTexture.use(GL_TEXTURE1);

	defaultShader.setInt("userTex", 0);
	defaultShader.setInt("userTex2", 1);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		float time = glfwGetTime();
		float valueX = sin(time) / 0.2f + 0.5f;
		float valueY = sin(time) / 0.2f + 0.5f;
		float valueZ = sin(time) / 0.2f + 0.5f;

		if (valueX < -0.5f)
		{
			valueX = -0.5f;
			valueY = -0.5f;
			valueZ = -0.5f;
		}
		else if (valueX > 0.5)
		{
			valueX = 0.5f;
			valueY = 0.5f;
			valueZ = 0.5f;
		}
		
		defaultShader.setFloat3("userColor", valueX, valueY, valueZ);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}