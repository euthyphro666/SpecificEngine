
#include "Screen.h"

namespace Core
{
	namespace Graphics
	{

		Screen::Screen(float width, float height)
		{
			this->CreateWindow(width, height);
			this->CreateRenderer(width, height);
		}

		void Screen::CreateWindow(float width, float height)
		{
			if (!glfwInit())
				throw __uncaught_exception;

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			window = glfwCreateWindow(width, height, "Something Specific", nullptr, nullptr);
			glfwMakeContextCurrent(window);

			glewExperimental = true;
			glewInit();
			glGetError();

			glViewport(0, 0, static_cast<int>(width), static_cast<int>(height));
			glEnable(GL_CULL_FACE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void Screen::CreateRenderer(float width, float height)
		{
			glm::mat4 projection = glm::ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);

			Shader shader = Resources::ResourceLoader::LoadShader("rsc/Shaders/sprite.vs", "rsc/Shaders/sprite.frag", nullptr, "sprite");

			shader.Use().SetInteger("image", 0);
			shader.SetMatrix4("projection", projection);

			renderer = new Renderer(shader);
		}

		Screen::~Screen() 
		{
			renderer->~Renderer();
		}

		bool Screen::ShouldClose()
		{
			return glfwWindowShouldClose(this->window);
		}

		void Screen::Start()
		{
			glClearColor(0.9f, 0.4f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			//glBegin(GL_2D);
		}

		void Screen::Stop()
		{
			//glEnd();
			glfwSwapBuffers(window);
		}
	}
}
