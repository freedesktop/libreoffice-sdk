/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: tplparam.cxx,v $
 * $Revision: 1.7 $
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
#include "tplparam.hxx"


// NOT FULLY DEFINED SERVICES
#include <ary/cpp/c_gate.hxx>
#include <ary/cpp/cp_type.hxx>


namespace ary
{
namespace cpp
{
namespace ut
{

TplParameter_Type::TplParameter_Type( Tid i_nType )
    :   nType(i_nType)
{
}

TplParameter_Type::~TplParameter_Type()
{
}

intt
TplParameter_Type::Compare(	const TemplateParameter & i_rOther ) const
{
    const TplParameter_Type * pOther
            = dynamic_cast< const TplParameter_Type* >( &i_rOther );
    if (pOther == 0)
        return -1;

    return static_cast<long>(nType.Value())
           - static_cast<long>(pOther->nType.Value());
}

void
TplParameter_Type::Get_Text( StreamStr &                    o_rOut,
                             const ary::cpp::Gate &	i_rGate ) const
{
    i_rGate.Types().Get_TypeText( o_rOut, nType );
}

}   // namespace ut
}   // namespace cpp
}   // namespace ary
