#include <sandbox/sandbox_app.h>

using sandbox::Sandbox;

void prepareSettings(Sandbox::Settings *settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(Sandbox, ci::app::RendererGl, prepareSettings)