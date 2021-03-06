$NetBSD: patch-mozilla_js_src_jit_arm_Architecture-arm.cpp,v 1.3 2015/09/21 05:03:45 ryoon Exp $

--- mozilla/js/src/jit/arm/Architecture-arm.cpp.orig	2015-09-02 09:27:31.000000000 +0000
+++ mozilla/js/src/jit/arm/Architecture-arm.cpp
@@ -16,7 +16,7 @@
 #include "jit/arm/Assembler-arm.h"
 #include "jit/RegisterSets.h"
 
-#if !defined(__linux__) || defined(ANDROID) || defined(JS_ARM_SIMULATOR)
+#if !defined(__linux__) || defined(ANDROID) || defined(JS_ARM_SIMULATOR) || defined(__NetBSD__)
 // The Android NDK and B2G do not include the hwcap.h kernel header, and it is not
 // defined when building the simulator, so inline the header defines we need.
 # define HWCAP_VFP        (1 << 6)
