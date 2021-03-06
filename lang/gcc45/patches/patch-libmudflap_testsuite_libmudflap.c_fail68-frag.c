$NetBSD$

--- libmudflap/testsuite/libmudflap.c/fail68-frag.c.orig	Wed May 21 19:48:59 2014
+++ libmudflap/testsuite/libmudflap.c/fail68-frag.c
@@ -0,0 +1,27 @@
+/* PR libmudflap/40778 */
+
+char p[32];
+static int j;
+
+__attribute__((noinline))
+static void foo (int i)
+{
+  if (j++ == 0)
+    p[i + 4] = 12;
+  else
+    p[i - 4] = 13;
+}
+
+int
+main ()
+{
+  foo (30);
+  foo (30);
+  foo (30);
+  return 0;
+}
+
+/* { dg-output "mudflap violation 1.*" } */
+/* { dg-output "Nearby object 1.*" } */
+/* { dg-output "mudflap object.*name.*p" } */
+/* { dg-do run { xfail *-*-* } } */
