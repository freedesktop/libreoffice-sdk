/*************************************************************************
 *
 *  OpenOffice.org - a multi-platform office productivity suite
 *
 *  $RCSfile: is_type.cxx,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: hr $ $Date: 2006-06-19 11:52:01 $
 *
 *  The Contents of this file are made available subject to
 *  the terms of GNU Lesser General Public License Version 2.1.
 *
 *
 *    GNU Lesser General Public License Version 2.1
 *    =============================================
 *    Copyright 2005 by Sun Microsystems, Inc.
 *    901 San Antonio Road, Palo Alto, CA 94303, USA
 *
 *    This library is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License version 2.1, as published by the Free Software Foundation.
 *
 *    This library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with this library; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *    MA  02111-1307  USA
 *
 ************************************************************************/


#include <precomp.h>
#include "is_type.hxx"


// NOT FULLY DEFINED SERVICES



namespace ary
{
namespace idl
{

namespace
{
const uintt C_nReservedElements = predefined::type_MAX;    // Skipping "0" and the built in types.
}


Type_Storage::Type_Storage( uintt               i_nBLOCK_SIZE_LOG_2,
                            uintt               i_nInitialNrOfBlocks )
    :   aContainer(i_nBLOCK_SIZE_LOG_2, C_nReservedElements, i_nInitialNrOfBlocks)
{
}

Type_Storage::~Type_Storage()
{
}

void
Type_Storage::EraseAll()
{
    aContainer.EraseAll();
}

void
Type_Storage::Save( PersistenceAdmin & ) const
{
    // KORR_FUTURE
}

void
Type_Storage::Load( PersistenceAdmin & )
{
    // KORR_FUTURE
}



}   // namespace idl
}   // namespace ary

