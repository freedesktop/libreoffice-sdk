/*************************************************************************
 *
 *  $RCSfile: icprivow.hxx,v $
 *
 *  $Revision: 1.1.1.1 $
 *
 *  last change: $Author: np $ $Date: 2002-03-08 14:45:30 $
 *
 *  The Contents of this file are made available subject to the terms of
 *  either of the following licenses
 *
 *         - GNU Lesser General Public License Version 2.1
 *         - Sun Industry Standards Source License Version 1.1
 *
 *  Sun Microsystems Inc., October, 2000
 *
 *  GNU Lesser General Public License Version 2.1
 *  =============================================
 *  Copyright 2000 by Sun Microsystems, Inc.
 *  901 San Antonio Road, Palo Alto, CA 94303, USA
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License version 2.1, as published by the Free Software Foundation.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *  MA  02111-1307  USA
 *
 *
 *  Sun Industry Standards Source License Version 1.1
 *  =================================================
 *  The contents of this file are subject to the Sun Industry Standards
 *  Source License Version 1.1 (the "License"); You may not use this file
 *  except in compliance with the License. You may obtain a copy of the
 *  License at http://www.openoffice.org/license.html.
 *
 *  Software provided under this License is provided on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
 *  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
 *  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
 *  See the License for the specific provisions governing your rights and
 *  obligations concerning the Software.
 *
 *  The Initial Developer of the Original Code is: Sun Microsystems, Inc.
 *
 *  Copyright: 2000 by Sun Microsystems, Inc.
 *
 *  All Rights Reserved.
 *
 *  Contributor(s): _______________________________________
 *
 *
 ************************************************************************/

#ifndef ARY_CPP_ICPRIVOW_HXX
#define ARY_CPP_ICPRIVOW_HXX



// USED SERVICES
    // BASE CLASSES
#include <ary/cpp/inpcontx.hxx>
    // COMPONENTS
    // PARAMETERS

namespace cpp
{



using ary::Cid;
using ary::OSid;

class Owner_Namespace : public ary::cpp::InputContext::Owner
{
  public:
                        Owner_Namespace();
    void                SetAnotherNamespace(
                            ary::cpp::Namespace &
                                                io_rScope );

  private:
    virtual void        do_Add_Class(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Enum(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Typedef(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Operation(
                                const udmstri &     i_sLocalName,
                                OSid                i_nSignature,
                                Cid                 i_nId,
                                bool                i_bIsStatic );
    virtual void        do_Add_Variable(
                                const udmstri &     i_sLocalName,
                                Cid                 i_nId,
                                bool                i_bIsConst,
                                bool                i_bIsStatic );
    virtual Cid         inq_Id() const;

    // DATA
    ary::cpp::Namespace *
                        pScope;
};

class Owner_Class : public ary::cpp::InputContext::Owner
{
  public:
                        Owner_Class();
    void                SetAnotherClass(
                            ary::cpp::Class &   io_rScope );
  private:
    virtual void        do_Add_Class(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Enum(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Typedef(
                            const udmstri &     i_sLocalName,
                            Cid                 i_nId );
    virtual void        do_Add_Operation(
                                const udmstri &     i_sLocalName,
                                OSid                i_nSignature,
                                Cid                 i_nId,
                                bool                i_bIsStatic );
    virtual void        do_Add_Variable(
                                const udmstri &     i_sLocalName,
                                Cid                 i_nId,
                                bool                i_bIsConst,
                                bool                i_bIsStatic );
    virtual Cid         inq_Id() const;

    // DATA
    ary::cpp::Class *   pScope;
};



}   // namespace cpp


#endif

