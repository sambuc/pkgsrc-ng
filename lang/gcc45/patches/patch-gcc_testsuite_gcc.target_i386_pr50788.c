$NetBSD$

--- gcc/testsuite/gcc.target/i386/pr50788.c.orig	Wed May 21 19:48:58 2014
+++ gcc/testsuite/gcc.target/i386/pr50788.c
@@ -0,0 +1,10 @@
+/* { dg-do compile } */
+/* { dg-options "-O2 -mavx -fpeel-loops -fstack-protector-all" } */
+
+typedef long long __m256i __attribute__ ((__vector_size__ (32)));
+typedef double __m256d __attribute__ ((__vector_size__ (32)));
+
+__m256d foo (__m256d *__P, __m256i __M)
+{
+  return __builtin_ia32_maskloadpd256 ( __P, __M);
+}
