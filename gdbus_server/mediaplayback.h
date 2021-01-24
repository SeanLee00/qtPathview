#ifndef MEDIAPLAYBACK_H
#define MEDIAPLAYBACK_H

#include "playback-generated.h"

class MediaPlayback
{
public:
    MediaPlayback();
    virtual ~MediaPlayback();

private:
    static void on_bus_acquired(GDBusConnection *connection,
                                const gchar     *name,
                                gpointer         user_data);

    static void on_name_acquired (GDBusConnection *connection,
                                  const gchar     *name,
                                  gpointer         user_data);

    static gboolean on_handle_play (examplePlayback         *interface,
                                    GDBusMethodInvocation   *invocation,
                                    gint                    trackIndex,
                                    gpointer                user_data);

private:
    static examplePlayback *m_obj;
    guint m_busId;
};

#endif // MEDIAPLAYBACK_H
