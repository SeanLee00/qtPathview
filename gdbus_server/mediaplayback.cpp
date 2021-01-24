#include "mediaplayback.h"

examplePlayback * MediaPlayback::m_obj = nullptr;

MediaPlayback::MediaPlayback()
{
    /* Register bus name */
    m_busId = g_bus_own_name (G_BUS_TYPE_SESSION,
                              "net.Makersweb.Examples.Media",
                              (GBusNameOwnerFlags)(G_BUS_NAME_OWNER_FLAGS_ALLOW_REPLACEMENT | G_BUS_NAME_OWNER_FLAGS_REPLACE),
                              on_bus_acquired,
                              on_name_acquired,
                              nullptr,
                              nullptr,
                              nullptr);
}

MediaPlayback::~MediaPlayback()
{

}

void MediaPlayback::on_bus_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
    g_print ("Acquired a message bus connection\n");

    m_obj = example_playback_skeleton_new();

    example_playback_set_current_track(m_obj, 0);

    /* Handle Play() D-Bus method invocations on the .Playback interface */
    g_signal_connect (m_obj,
                      "handle-play",
                      G_CALLBACK (on_handle_play),
                      nullptr); /* user_data */

    GError *error = nullptr;

    if (!g_dbus_interface_skeleton_export ( G_DBUS_INTERFACE_SKELETON (m_obj),
                                            connection,
                                            "/path/of/dbus_object",
                                            &error))
    {
        /* handle error */
    }
}

void MediaPlayback::on_name_acquired(GDBusConnection *connection, const gchar *name, gpointer user_data)
{
    g_print ("Acquired the name %s\n", name);
}

gboolean MediaPlayback::on_handle_play(examplePlayback *interface, GDBusMethodInvocation *invocation, gint trackIndex, gpointer user_data)
{
    if(trackIndex >= 0){
        /* Play track Sequence */
        example_playback_set_current_track(m_obj, trackIndex);

        /* D-Bus 메서드 호출 완료 함수 */
        example_playback_complete_play(interface, invocation);
    }
    else {
        g_dbus_method_invocation_return_dbus_error (invocation,
                                                    "Media.Playback.Error.play",
                                                    "invalid track.");
    }

    return TRUE;
}
