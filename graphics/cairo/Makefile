# $NetBSD: Makefile,v 1.139 2015/04/25 14:23:07 tnn Exp $

PKGREVISION= 1
.include "../../graphics/cairo/Makefile.common"

TEST_TARGET=			check

.include "options.mk"

.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2.95
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.1.9
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# include?
#.include "../../print/libspectre/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.30.0
.include "../../x11/pixman/buildlink3.mk"
.if (${OPSYS} == "NetBSD" && ${OS_VARIANT} == "Minix")
CPPFLAGS+= -DCAIRO_NO_MUTEX=1
.else
.include "../../mk/pthread.buildlink3.mk"
.endif # !(${OPSYS} == "NetBSD" && ${OS_VARIANT} == "Minix")
.include "../../mk/bsd.pkg.mk"
