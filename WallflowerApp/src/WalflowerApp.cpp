#include "Wallflower/Application.h"
#include "Wallflower/EntryPoint.h"

#include "Wallflower/Image.h"

class ExampleLayer : public Wallflower::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();

		ImGui::ShowDemoWindow();
	}
};

Wallflower::Application* Wallflower::CreateApplication(int argc, char** argv)
{
	Wallflower::ApplicationSpecification spec;
	spec.Name = "Wallflower Example";

	Wallflower::Application* app = new Wallflower::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});
	return app;
}