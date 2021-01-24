/*
 * Generated by gdbus-codegen 2.56.4. DO NOT EDIT.
 *
 * The license of this code is the same as for the D-Bus interface description
 * it was derived from.
 */

#ifndef __PLAYBACK_GENERATED_H__
#define __PLAYBACK_GENERATED_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for net.Makersweb.Media.Playback */

#define EXAMPLE_TYPE_PLAYBACK (example_playback_get_type ())
#define EXAMPLE_PLAYBACK(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), EXAMPLE_TYPE_PLAYBACK, examplePlayback))
#define EXAMPLE_IS_PLAYBACK(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), EXAMPLE_TYPE_PLAYBACK))
#define EXAMPLE_PLAYBACK_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), EXAMPLE_TYPE_PLAYBACK, examplePlaybackIface))

struct _examplePlayback;
typedef struct _examplePlayback examplePlayback;
typedef struct _examplePlaybackIface examplePlaybackIface;

struct _examplePlaybackIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_next) (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_pause) (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

  gboolean (*handle_play) (
    examplePlayback *object,
    GDBusMethodInvocation *invocation,
    gint arg_index);

  gboolean (*handle_prev) (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

  gint  (*get_current_track) (examplePlayback *object);

  void (*playback_state_changed) (
    examplePlayback *object,
    gint arg_state);

};

GType example_playback_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *example_playback_interface_info (void);
guint example_playback_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void example_playback_complete_play (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

void example_playback_complete_pause (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

void example_playback_complete_prev (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);

void example_playback_complete_next (
    examplePlayback *object,
    GDBusMethodInvocation *invocation);



/* D-Bus signal emissions functions: */
void example_playback_emit_playback_state_changed (
    examplePlayback *object,
    gint arg_state);



/* D-Bus method calls: */
void example_playback_call_play (
    examplePlayback *proxy,
    gint arg_index,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean example_playback_call_play_finish (
    examplePlayback *proxy,
    GAsyncResult *res,
    GError **error);

gboolean example_playback_call_play_sync (
    examplePlayback *proxy,
    gint arg_index,
    GCancellable *cancellable,
    GError **error);

void example_playback_call_pause (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean example_playback_call_pause_finish (
    examplePlayback *proxy,
    GAsyncResult *res,
    GError **error);

gboolean example_playback_call_pause_sync (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GError **error);

void example_playback_call_prev (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean example_playback_call_prev_finish (
    examplePlayback *proxy,
    GAsyncResult *res,
    GError **error);

gboolean example_playback_call_prev_sync (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GError **error);

void example_playback_call_next (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean example_playback_call_next_finish (
    examplePlayback *proxy,
    GAsyncResult *res,
    GError **error);

gboolean example_playback_call_next_sync (
    examplePlayback *proxy,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
gint example_playback_get_current_track (examplePlayback *object);
void example_playback_set_current_track (examplePlayback *object, gint value);


/* ---- */

#define EXAMPLE_TYPE_PLAYBACK_PROXY (example_playback_proxy_get_type ())
#define EXAMPLE_PLAYBACK_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), EXAMPLE_TYPE_PLAYBACK_PROXY, examplePlaybackProxy))
#define EXAMPLE_PLAYBACK_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), EXAMPLE_TYPE_PLAYBACK_PROXY, examplePlaybackProxyClass))
#define EXAMPLE_PLAYBACK_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), EXAMPLE_TYPE_PLAYBACK_PROXY, examplePlaybackProxyClass))
#define EXAMPLE_IS_PLAYBACK_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), EXAMPLE_TYPE_PLAYBACK_PROXY))
#define EXAMPLE_IS_PLAYBACK_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), EXAMPLE_TYPE_PLAYBACK_PROXY))

typedef struct _examplePlaybackProxy examplePlaybackProxy;
typedef struct _examplePlaybackProxyClass examplePlaybackProxyClass;
typedef struct _examplePlaybackProxyPrivate examplePlaybackProxyPrivate;

struct _examplePlaybackProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  examplePlaybackProxyPrivate *priv;
};

struct _examplePlaybackProxyClass
{
  GDBusProxyClass parent_class;
};

GType example_playback_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (examplePlaybackProxy, g_object_unref)
#endif

void example_playback_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
examplePlayback *example_playback_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
examplePlayback *example_playback_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void example_playback_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
examplePlayback *example_playback_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
examplePlayback *example_playback_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define EXAMPLE_TYPE_PLAYBACK_SKELETON (example_playback_skeleton_get_type ())
#define EXAMPLE_PLAYBACK_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), EXAMPLE_TYPE_PLAYBACK_SKELETON, examplePlaybackSkeleton))
#define EXAMPLE_PLAYBACK_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), EXAMPLE_TYPE_PLAYBACK_SKELETON, examplePlaybackSkeletonClass))
#define EXAMPLE_PLAYBACK_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), EXAMPLE_TYPE_PLAYBACK_SKELETON, examplePlaybackSkeletonClass))
#define EXAMPLE_IS_PLAYBACK_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), EXAMPLE_TYPE_PLAYBACK_SKELETON))
#define EXAMPLE_IS_PLAYBACK_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), EXAMPLE_TYPE_PLAYBACK_SKELETON))

typedef struct _examplePlaybackSkeleton examplePlaybackSkeleton;
typedef struct _examplePlaybackSkeletonClass examplePlaybackSkeletonClass;
typedef struct _examplePlaybackSkeletonPrivate examplePlaybackSkeletonPrivate;

struct _examplePlaybackSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  examplePlaybackSkeletonPrivate *priv;
};

struct _examplePlaybackSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType example_playback_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (examplePlaybackSkeleton, g_object_unref)
#endif

examplePlayback *example_playback_skeleton_new (void);


G_END_DECLS

#endif /* __PLAYBACK_GENERATED_H__ */
