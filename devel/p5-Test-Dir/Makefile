# $NetBSD: Makefile,v 1.4 2015/06/12 10:49:48 wiz Exp $
#

DISTNAME=		Test-Dir-1.014
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Dir/
COMMENT=		Test directory attributes
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/Dir/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
