#include "textedit.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create("org.gtkmm.textedit");

	return app->make_window_and_run<TextEdit>(argc, argv);
};
