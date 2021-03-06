$NetBSD: patch-installer_dcheck.py,v 1.1 2015/08/27 23:53:24 khorben Exp $

Locate libraries on systems without ldconfig(8)

This only looks for libraries in pkgsrc's own library folder.

--- installer/dcheck.py.orig	2015-06-07 19:25:11.000000000 +0000
+++ installer/dcheck.py
@@ -99,6 +99,8 @@ def check_lib(lib, min_ver=0):
         #    pass
         #else:
         return True
+    elif check_file(lib+".so","/usr/lib"):
+        return True
     else:
         log.debug("Not found.")
         return False
