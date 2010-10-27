/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2000, 2010 Oracle and/or its affiliates.
 *
 * OpenOffice.org - a multi-platform office productivity suite
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

#ifndef ARY_CPP_C_MACRO_HXX
#define ARY_CPP_C_MACRO_HXX


// USED SERVICES
    // BASE CLASSES
#include <ary/cpp/c_de.hxx>



namespace ary
{
namespace cpp
{


/** A C/C++ macro ("#define ABC(a,b)") statement, but no simple define.

    @see Define
*/
class Macro : public DefineEntity
{
  public:
    enum E_ClassId { class_id = 1602 };

                        Macro();
                        Macro(      /// Used for: #define DEFINE xyz
                            const String  &     i_name,
                            const StringVector &
                                                i_params,
                            const StringVector &
                                                i_definition,
                            loc::Le_id          i_declaringFile );
                        ~Macro();
    const StringVector &  Params() const          { return aParams; }

  private:
    // Interface csv::ConstProcessorClient
    virtual void        do_Accept(
                            csv::ProcessorIfc & io_processor ) const;
    // Interface ary::Object
    virtual ClassId     get_AryClass() const;

    // Interface DefineEntity:
    virtual const StringVector &
                        inq_DefinitionText() const;
    // DATA
    StringVector          aParams;
    StringVector          aDefinition;
};




}   // namespace cpp
}   // namespace ary
#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
