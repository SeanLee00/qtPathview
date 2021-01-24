#include "mediaplayback.h"

gint main (gint argc, gchar *argv[]){

    GMainLoop *loop;
    guint id;

    g_type_init ();

    loop = g_main_loop_new (nullptr, FALSE);

    MediaPlayback * playback = new MediaPlayback;

    g_main_loop_run (loop);

    g_bus_unown_name (id);
    g_main_loop_unref (loop);

    return 0;
}
