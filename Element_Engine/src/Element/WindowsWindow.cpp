#include "elmpch.h"
#include "WindowsWindow.h"


namespace ELM {
	static bool is_GLFWInitialized = false;
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		//debug shit here("Creating window [0] ((), (2))", props.Title, props.Width, props.Height);

		if (!is_GLFWInitialized)
		{
			int success = glfwInit();
			//core assert here
			//ELM_CORE_ASSERT(success, "Could not initialize GLFW!")
			is_GLFWInitialized = 1;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}
	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}
}