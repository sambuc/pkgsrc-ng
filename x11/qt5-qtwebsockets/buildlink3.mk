# $NetBSD: buildlink3.mk,v 1.3 2015/04/25 14:25:18 tnn Exp $

BUILDLINK_TREE+=	qt5-websockets

.if !defined(QT5_WEBSOCKETS_BUILDLINK3_MK)
QT5_WEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-websockets+=	qt5-websockets>=5.4.0
BUILDLINK_ABI_DEPENDS.qt5-websockets?=	qt5-websockets>=5.4.0nb2
BUILDLINK_PKGSRCDIR.qt5-websockets?=	../../x11/qt5-qtwebsockets

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.endif	# QT5_WEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-websockets
