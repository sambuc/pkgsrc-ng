$NetBSD$

--- gcc/libgcov.c.orig	Sat Nov 28 16:21:00 2009
+++ gcc/libgcov.c
@@ -40,6 +40,11 @@ see the files COPYING3 and COPYING.RUNTIME respectivel
 #define GCOV_LINKAGE /* nothing */
 #endif
 #endif
+
+#ifndef L_gcov_merge_add
+#include "gcov-minix-fs-wrapper.h"
+#endif
+
 #include "gcov-io.h"
 
 #if defined(inhibit_libc)
@@ -152,7 +157,7 @@ gcov_version (struct gcov_info *ptr, gcov_unsigned_t v
    in two separate programs, and we must keep the two program
    summaries separate.  */
 
-static void
+void
 gcov_exit (void)
 {
   struct gcov_info *gi_ptr;
@@ -564,7 +569,7 @@ __gcov_init (struct gcov_info *info)
       gcov_crc32 = crc32;
 
       if (!gcov_list)
-	atexit (gcov_exit);
+	atexit (gcov_exit_wrapper);
 
       info->next = gcov_list;
       gcov_list = info;
