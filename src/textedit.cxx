#include "textedit.h"

TextEdit::TextEdit()
: m_VBox(Gtk::Orientation::VERTICAL),
  m_Button_Quit("_Quit",true),
  m_Button_Buffer1("Use buffer 1"),
  m_Button_Buffer2("Use buffer 2")
{
	set_title("TextEditor");
	set_default_size(400,400);

	m_VBox.set_margin(5);
	set_child(m_VBox);

	// Add the TreeView, inside a scrolled window with a button underneath
	m_ScrolledWindow.set_child(m_TextView);
	
	//Only show scroll bars when neccassary
	m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
	m_ScrolledWindow.set_expand();

	m_VBox.append(m_ScrolledWindow);
	
	// attach buttons
	m_VBox.append(m_ButtonBox);

	m_Button_Buffer1.set_hexpand(true);
	m_Button_Buffer1.set_halign(Gtk::Align::END);
	m_ButtonBox.append(m_Button_Buffer1);
	m_ButtonBox.append(m_Button_Buffer2);
	m_ButtonBox.append(m_Button_Quit);
	m_ButtonBox.set_margin(5);
	m_ButtonBox.set_spacing(5);

	//conect signals
	m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &TextEdit::on_button_quit));

	m_Button_Buffer1.signal_clicked().connect(sigc::mem_fun(*this, &TextEdit::on_button_buff1));

	m_Button_Buffer2.signal_clicked().connect(sigc::mem_fun(*this, &TextEdit::on_button_buff2));

	fill_buffers();
	on_button_buff1();
};

void TextEdit::fill_buffers()
{
	m_refTextBuffer1 = Gtk::TextBuffer::create();
	m_refTextBuffer1->set_text("TextBuffer1, go ahead and edit this.");

	m_refTextBuffer2 = Gtk::TextBuffer::create();
	m_refTextBuffer2->set_text("TextBuffer2 Text.");
};

TextEdit::~TextEdit()
{
};

void TextEdit::on_button_quit()
{
	hide();
};

void TextEdit::on_button_buff1()
{
	m_TextView.set_buffer(m_refTextBuffer1);
};

void TextEdit::on_button_buff2()
{

	m_TextView.set_buffer(m_refTextBuffer2);
};
