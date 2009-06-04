/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: c_enuval.hxx,v $
 * $Revision: 1.4 $
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

#ifndef ARY_CPP_C_ENUVAL_HXX
#define ARY_CPP_C_ENUVAL_HXX


// USED SERVICES
    // BASE CLASSES
#include <ary/cpp/c_ce.hxx>
    // OTHER
#include <ary/cessentl.hxx>
#include <ary/cpp/c_types4cpp.hxx>



namespace ary
{
namespace cpp
{



/** A C++ enum value declaration and definition.
*/
class EnumValue : public CodeEntity
{
  public:
    enum E_ClassId { class_id = 1006 };

    // LIFECYCLE
                        EnumValue(
                            const String  &     i_sLocalName,
                            Ce_id               i_nOwner,
                            String              i_sInitialisation );
                        ~EnumValue();
    // INQUIRY
    const String  &     Initialisation() const;

  private:
    // Interface csv::ConstProcessorClient
    virtual void        do_Accept(
                            csv::ProcessorIfc & io_processor ) const;

    // Interface ary::cpp::CodeEntity
    virtual const String  &
                        inq_LocalName() const;
    virtual Cid         inq_Owner() const;
    virtual Lid			inq_Location() const;

    // Interface ary::cpp::CppEntity
    virtual ClassId     get_AryClass() const;

    // DATA
    CeEssentials		aEssentials;
    String              sInitialisation;
};




// IMPLEMENTATION
inline const String  &
EnumValue::Initialisation() const
    { return sInitialisation; }




}   // namespace cpp
}   // namespace ary
#endif
