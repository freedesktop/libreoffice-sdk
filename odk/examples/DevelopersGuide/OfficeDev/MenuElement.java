/*************************************************************************
 *
 *  $RCSfile: MenuElement.java,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: rt $ $Date: 2005-01-31 16:35:27 $
 *
 *  The Contents of this file are made available subject to the terms of
 *  the BSD license.
 *  
 *  Copyright (c) 2003 by Sun Microsystems, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Sun Microsystems, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 *  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 *  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *     
 *************************************************************************/

import com.sun.star.lang.XServiceInfo;
import com.sun.star.uno.UnoRuntime;

// A helper class to determine the menu element type
public class MenuElement
{
    static public boolean IsMenuEntry( com.sun.star.beans.XPropertySet xMenuElement ) {
        com.sun.star.lang.XServiceInfo xServiceInfo =
            (com.sun.star.lang.XServiceInfo)UnoRuntime.queryInterface(
                com.sun.star.lang.XServiceInfo.class, xMenuElement );

        return xServiceInfo.supportsService( "com.sun.star.ui.ActionTrigger" );
    }
    
    static public boolean IsMenuSeparator( com.sun.star.beans.XPropertySet xMenuElement ) {
        com.sun.star.lang.XServiceInfo xServiceInfo =
            (com.sun.star.lang.XServiceInfo)UnoRuntime.queryInterface(
                com.sun.star.lang.XServiceInfo.class, xMenuElement );

        return xServiceInfo.supportsService( "com.sun.star.ui.ActionTriggerSeparator" );
    }
}
