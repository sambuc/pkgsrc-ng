# $NetBSD: buildlink3.mk,v 1.27 2015/06/14 22:02:08 prlw1 Exp $

BUILDLINK_TREE+=	gtk3

.if !defined(GTK3_BUILDLINK3_MK)
GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0.0
BUILDLINK_ABI_DEPENDS.gtk3+=	gtk3+>=3.14.5nb3
BUILDLINK_PKGSRCDIR.gtk3?=	../../x11/gtk3

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := gtk3
.include "../../mk/pkg-build-options.mk"

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk3:Mx11)
.  if !empty(PKG_BUILD_OPTIONS.gtk3:Mgtk3-atk-bridge)
.  include "../../devel/at-spi2-atk/buildlink3.mk"
.  endif
.include "../../x11/libXcursor/buildlink3.mk"
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.2nb2
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.endif
.endif # GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk3
