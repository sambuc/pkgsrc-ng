# $NetBSD: Makefile,v 1.5 2015/06/12 10:48:57 wiz Exp $

DISTNAME=	Carp-Always-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Carp-Always/
COMMENT=	Perl5 module which warns and dies noisily with stack backtraces
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

PERL5_PACKLIST=		auto/Carp/Always/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
