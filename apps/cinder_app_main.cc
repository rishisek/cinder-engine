#include <ikaruga/app/ikaruga_app.h>

using ikaruga::IkarugaApp;

void prepareSettings(IkarugaApp::Settings *settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(IkarugaApp, ci::app::RendererGl, prepareSettings)