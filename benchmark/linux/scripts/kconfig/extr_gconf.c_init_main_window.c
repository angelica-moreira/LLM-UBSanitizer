#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  gchar ;
struct TYPE_9__ {int /*<<< orphan*/  window; } ;
struct TYPE_8__ {TYPE_1__* prompt; } ;
struct TYPE_7__ {int /*<<< orphan*/  text; } ;
typedef  int /*<<< orphan*/  GtkWidget ;
typedef  int /*<<< orphan*/  GtkTextBuffer ;
typedef  int /*<<< orphan*/  GtkStyle ;
typedef  int /*<<< orphan*/  GtkCheckMenuItem ;
typedef  int /*<<< orphan*/  GladeXML ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GTK_TEXT_VIEW (void*) ; 
 int /*<<< orphan*/  GTK_WINDOW (TYPE_3__*) ; 
 int /*<<< orphan*/  PANGO_WEIGHT_BOLD ; 
 void* back_btn ; 
 int /*<<< orphan*/  conf_changed ; 
 int /*<<< orphan*/  conf_set_changed_callback (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_error (char*) ; 
 void* glade_xml_get_widget (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * glade_xml_new (int /*<<< orphan*/  const*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glade_xml_signal_autoconnect (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_check_menu_item_set_active (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* gtk_text_buffer_create_tag (int /*<<< orphan*/ *,char*,char*,...) ; 
 int /*<<< orphan*/ * gtk_text_view_get_buffer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gtk_widget_get_style (TYPE_3__*) ; 
 int /*<<< orphan*/  gtk_widget_set_sensitive (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_widget_show (TYPE_3__*) ; 
 int /*<<< orphan*/  gtk_window_set_title (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* hpaned ; 
 TYPE_3__* main_wnd ; 
 int /*<<< orphan*/  replace_button_icon (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ **) ; 
 TYPE_2__ rootmenu ; 
 void* save_btn ; 
 void* save_menu_item ; 
 int /*<<< orphan*/  show_name ; 
 int /*<<< orphan*/  show_range ; 
 int /*<<< orphan*/  show_value ; 
 void* tag1 ; 
 void* tag2 ; 
 void* text_w ; 
 void* tree1_w ; 
 void* tree2_w ; 
 void* vpaned ; 
 scalar_t__ xpm_single_view ; 
 scalar_t__ xpm_split_view ; 
 scalar_t__ xpm_tree_view ; 

__attribute__((used)) static void init_main_window(const gchar *glade_file)
{
	GladeXML *xml;
	GtkWidget *widget;
	GtkTextBuffer *txtbuf;
	GtkStyle *style;

	xml = glade_xml_new(glade_file, "window1", NULL);
	if (!xml)
		g_error("GUI loading failed !\n");
	glade_xml_signal_autoconnect(xml);

	main_wnd = glade_xml_get_widget(xml, "window1");
	hpaned = glade_xml_get_widget(xml, "hpaned1");
	vpaned = glade_xml_get_widget(xml, "vpaned1");
	tree1_w = glade_xml_get_widget(xml, "treeview1");
	tree2_w = glade_xml_get_widget(xml, "treeview2");
	text_w = glade_xml_get_widget(xml, "textview3");

	back_btn = glade_xml_get_widget(xml, "button1");
	gtk_widget_set_sensitive(back_btn, FALSE);

	widget = glade_xml_get_widget(xml, "show_name1");
	gtk_check_menu_item_set_active((GtkCheckMenuItem *) widget,
				       show_name);

	widget = glade_xml_get_widget(xml, "show_range1");
	gtk_check_menu_item_set_active((GtkCheckMenuItem *) widget,
				       show_range);

	widget = glade_xml_get_widget(xml, "show_data1");
	gtk_check_menu_item_set_active((GtkCheckMenuItem *) widget,
				       show_value);

	save_btn = glade_xml_get_widget(xml, "button3");
	save_menu_item = glade_xml_get_widget(xml, "save1");
	conf_set_changed_callback(conf_changed);

	style = gtk_widget_get_style(main_wnd);
	widget = glade_xml_get_widget(xml, "toolbar1");

	replace_button_icon(xml, main_wnd->window, style,
			    "button4", (gchar **) xpm_single_view);
	replace_button_icon(xml, main_wnd->window, style,
			    "button5", (gchar **) xpm_split_view);
	replace_button_icon(xml, main_wnd->window, style,
			    "button6", (gchar **) xpm_tree_view);

	txtbuf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_w));
	tag1 = gtk_text_buffer_create_tag(txtbuf, "mytag1",
					  "foreground", "red",
					  "weight", PANGO_WEIGHT_BOLD,
					  NULL);
	tag2 = gtk_text_buffer_create_tag(txtbuf, "mytag2",
					  /*"style", PANGO_STYLE_OBLIQUE, */
					  NULL);

	gtk_window_set_title(GTK_WINDOW(main_wnd), rootmenu.prompt->text);

	gtk_widget_show(main_wnd);
}