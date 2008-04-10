/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: it_ce.hxx,v $
 * $Revision: 1.5 $
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

#ifndef ARY_IDL_IT_CE_HXX
#define ARY_IDL_IT_CE_HXX

// BASE CLASSES
#include <ary/idl/i_type.hxx>




namespace ary
{
namespace idl
{


/** A named ->Type related to its corresponding
     ->CodeEntity.
*/
class Ce_Type : public Type
{
  public:
    enum E_ClassId { class_id = 2201 };

    // LIFECYCLE
                        Ce_Type(
                            Ce_id               i_nRelatedCe,
                            Type_id             i_nTemplateType = Type_id(0) );
    virtual             ~Ce_Type();

    // INQUIRY
    Ce_id               RelatedCe() const       { return nRelatedCe; }
    Type_id             TemplateType() const    { return nTemplateType; }

  private:
    // Interface csv::ConstProcessorClient:
    virtual void        do_Accept(
                            csv::ProcessorIfc & io_processor ) const;
    // Interface Object:
    virtual ClassId     get_AryClass() const;

    // Interface Type:
    virtual void        inq_Get_Text(
                            StringVector &      o_module,
                            String &            o_name,
                            Ce_id &             o_nRelatedCe,
                            int &               o_nSequemceCount,
                            const Gate &        i_rGate ) const;
    virtual Type_id     inq_TemplateParameterType() const;

    // DATA
    Ce_id               nRelatedCe;
    Type_id             nTemplateType;
};




}   // namespace idl
}   // namespace ary
#endif
