#ifndef GTKMM_TEXTEDIT_H
#define GTKMM_TEXTEDIT_H

#include <gtkmm.h>

class TextEdit : public Gtk::Window
{
	public:
		TextEdit();
		virtual ~TextEdit();

	protected:

		void fill_buffers();

		//signal handlers
		void on_button_quit();
		void on_button_buff1();
		void on_button_buff2();

		//child widgets
		Gtk::Box m_VBox;

		Gtk::ScrolledWindow m_ScrolledWindow;
		Gtk::TextView m_TextView;

		Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2;

		Gtk::Box m_ButtonBox;
		Gtk::Button m_Button_Quit, m_Button_Buffer1, m_Button_Buffer2;

};

#endif 
