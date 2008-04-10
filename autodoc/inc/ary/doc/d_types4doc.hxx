/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: d_types4doc.hxx,v $
 * $Revision: 1.3 $
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

#ifndef ARY_DOC_D_TYPES4DOC_HXX
#define ARY_DOC_D_TYPES4DOC_HXX

// USED SERVICES



namespace ary
{
namespace doc
{


/** Type of a documentation: multiple lines or single line.
*/
enum E_BlockType
{
    dbt_none = 0,
    dbt_multiline,
    dbt_singleline
};

/** Type of documentation text: with html or without.
*/
enum E_TextType
{
    dtt_none = 0,
    dtt_plain,
    dtt_html
};

namespace nodetype
{

typedef int id;

}   //  namespace nodetype



}   //  namespace doc
}   //  namespace ary
#endif
