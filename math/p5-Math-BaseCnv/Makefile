# $NetBSD: Makefile,v 1.12 2015/06/12 10:50:28 wiz Exp $
#

DISTNAME=	Math-BaseCnv-1.8.B59BrZX
PKGNAME=	p5-${DISTNAME:C:\.[^.]*$::}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-BaseCnv/
COMMENT=	Fast functions to CoNVert between number Bases
LICENSE=	gnu-gpl-v3

# actually, TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage

PERL5_PACKLIST=		auto/Math/BaseCnv/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
