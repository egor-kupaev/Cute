#include <cute/testing/clear_scene.hpp>
#include <imgui.h>

#include "../internal/GlWrappers.hpp"

namespace Cute::Testing
{

void ClearScene::doRender()
{
  ImGui::Begin("ClearColor Widget");

  ImGui::Text("Choose clear color");
  ImGui::ColorEdit3("Clear color:", colors_);

  ImGui::End();

  Gl::ClearColor(colors_[0], colors_[1], colors_[2], 1.0f);
  Gl::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ClearScene::doInitialize()
{
  // Nothing to initialize
}

void ClearScene::doFinalize()
{
  // Nothing to finalize
}
}
