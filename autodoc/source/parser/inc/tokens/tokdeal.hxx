/*************************************************************************
 *
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * 
 * Copyright 2008 by Sun Microsystems, Inc.
 *
 * OpenOffice.org - a multi-platform office productivity suite
 *
 * $RCSfile: tokdeal.hxx,v $
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

#ifndef ADC_TOKDEAL_HXX
#define ADC_TOKDEAL_HXX



// USED SERVICES
    // BASE CLASSES
    // COMPONENTS
    // PARAMETERS

namespace cpp
{
    class Distributor;
}


class TokenDealer

{
  public:
    virtual				~TokenDealer() {}

    virtual void		Deal_Eol() = 0;
    virtual void		Deal_Eof() = 0;
    virtual cpp::Distributor *
                        AsDistributor() = 0;
};


#if 0
class TokenDealer

{
  public:
    virtual void		Deal_IdlCode(
                            idl::Token & 		let_drToken );
    virtual void		Deal_UdkDocu(
                            udoc::Token & 		let_drToken );
    virtual void		Deal_JavaCode(
                            java::Token & 		let_drToken );
    virtual void		Deal_SBasicCode(
                            sbasic::Token & 	let_drToken );
};

#endif // 0



#endif

