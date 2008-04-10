/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: d_unit.hxx,v $
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

#ifndef ARY_DOC_D_UNIT_HXX
#define ARY_DOC_D_UNIT_HXX

// BASE CLASSES
#include <ary/doc/d_node.hxx>

// USED SERVICES
#include <ary/doc/d_hypertext.hxx>




namespace ary
{
namespace doc
{


/** A documentation with a title and a text.

    @example
    ReturnValue
        The number of items counted.
*/
class Unit : public Node
{
  public:

    // LIFECYCLE
    explicit    		Unit(
                            nodetype::id        i_id );
    virtual				~Unit();

    // INQUIRY
    const HyperText &   Doc() const;

    // ACESS
    HyperText &         Doc();

  private:
    // Interface csv::ConstProcessorClient:
    virtual void        do_Accept(
                            csv::ProcessorIfc & io_processor ) const;
    // DATA
    HyperText           aDoc;
};




// IMPLEMENTATION
inline const HyperText &
Unit::Doc() const
{
    return aDoc;
}

inline HyperText &
Unit::Doc()
{
    return aDoc;
}




}   // namespace doc
}   // namespace ary
#endif
