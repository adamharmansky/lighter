#include <gtk/gtk.h>
#include <unistd.h>

GtkWidget *slider;

static void
chg(GtkApplication* app, gpointer datalmao)
{
	char msg[16];
	sprintf(msg, "light -S %d\n", (int)gtk_range_get_value(GTK_RANGE(slider)));
	system(msg);
}

static void
activate(GtkApplication* app, gpointer datalmao)
{
	GtkWidget *window;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Brightness");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
	slider = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, gtk_adjustment_new(10,1,100,1,1,1));
	gtk_container_add(GTK_CONTAINER(window), slider);
	g_signal_connect(slider, "value-changed", G_CALLBACK(chg), NULL);
	gtk_widget_show_all(window);
}

int
main()
{
	GtkApplication* app = gtk_application_new("org.adamharmansky.lighter", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	return g_application_run(G_APPLICATION(app), 0, (char**)NULL);
}
