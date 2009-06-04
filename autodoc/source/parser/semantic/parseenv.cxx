/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: parseenv.cxx,v $
 * $Revision: 1.6 $
 *
 * This file is part of OpenOffice.org.
 *
 * OpenOffice.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 3
 * only, as published by the Free Software Foundation.
 *
 * OpenOffice.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3 for more details
 * (a copy is included in the LICENSE file that accompanied this code).
 *
 * You should have received a copy of the GNU Lesser General Public License
 * version 3 along with OpenOffice.org.  If not, see
 * <http://www.openoffice.org/license.html>
 * for a copy of the LGPLv3 License.
 *
 ************************************************************************/

#include <precomp.h>
#include <semantic/parseenv.hxx>


// NOT FULLY DECLARED SERVICES
#include <ary/doc/d_oldcppdocu.hxx>
#include <x_parse.hxx>


void
ParseEnvironment::Enter( E_EnvStackAction	i_eWayOfEntering )
{
    switch (i_eWayOfEntering)
    {
        case push:
                InitData();
                if ( Parent() != 0 )
                {
                    csv_assert( Parent()->CurSubPeUse() != 0 );
                    Parent()->CurSubPeUse()->InitParse();
                }
                break;
        case pop_success:
                break;
        case pop_failure:
                break;
        default:
            csv_assert(false);
    }	// end switch
}

void
ParseEnvironment::Leave( E_EnvStackAction	i_eWayOfLeaving )
{
    switch (i_eWayOfLeaving)
    {
        case push:
                break;
        case pop_success:
                TransferData();
                if ( Parent() != 0 )
                {
                    csv_assert( Parent()->CurSubPeUse() != 0 );
                    Parent()->CurSubPeUse()->GetResults();
                }
                break;
        case pop_failure:
                break;
        default:
            csv_assert(false);
    }	// end switch
}

ParseEnvironment::ParseEnvironment( ParseEnvironment *	i_pParent )
    :	pParent(i_pParent),
        // pDocu,
        pCurSubPe(0)
{
}
