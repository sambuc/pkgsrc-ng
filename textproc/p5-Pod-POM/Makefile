# $NetBSD: Makefile,v 1.32 2015/09/06 20:42:33 wiz Exp $

DISTNAME=	Pod-POM-2.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-POM/
COMMENT=	Perl module to format POD into an object format
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-File-Slurper-[0-9]*:../../devel/p5-File-Slurper

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Pod/POM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
