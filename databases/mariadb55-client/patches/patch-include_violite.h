$NetBSD: patch-include_violite.h,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- include/violite.h.orig	2015-02-13 12:07:01.000000000 +0000
+++ include/violite.h
@@ -212,8 +212,14 @@ struct st_vio
   HANDLE hPipe;
   my_bool		localhost;	/* Are we from localhost? */
   int			fcntl_mode;	/* Buffered fcntl(sd,F_GETFL) */
+#if defined(_SCO_DS)
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+  struct sockaddr_in	local;		/* Local internet address */
+  struct sockaddr_in	remote;		/* Remote internet address */
+#else
   struct sockaddr_storage	local;		/* Local internet address */
   struct sockaddr_storage	remote;		/* Remote internet address */
+#endif
   int addrLen;                          /* Length of remote address */
   enum enum_vio_type	type;		/* Type of connection */
   char			desc[30];	/* String description */
@@ -233,7 +239,12 @@ struct st_vio
   int     (*viokeepalive)(Vio*, my_bool);
   int     (*fastsend)(Vio*);
   my_bool (*peer_addr)(Vio*, char *, uint16*, size_t);
+/* SCO OpenServer 5.0.7/3.2 has no sockaddr_storage. */
+#if defined(_SCO_DS)
+  void    (*in_addr)(Vio*, struct sockaddr_in*);
+#else
   void    (*in_addr)(Vio*, struct sockaddr_storage*);
+#endif
   my_bool (*should_retry)(Vio*);
   my_bool (*was_interrupted)(Vio*);
   int     (*vioclose)(Vio*);
