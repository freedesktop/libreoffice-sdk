/*************************************************************************
 *
 *  $RCSfile: DrawViewDemo.java,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: hr $ $Date: 2004-02-02 19:53:27 $
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

// __________ Imports __________

// base classes
import com.sun.star.uno.UnoRuntime;
import com.sun.star.lang.*;

// property access
import com.sun.star.beans.*;

// name access
import com.sun.star.container.*;

// application specific classes
import com.sun.star.drawing.*;

// XModel, XController
import com.sun.star.frame.*;

// XViewDataSupplier
import com.sun.star.document.*;


// __________ Implementation __________

/** text demo
    @author Sven Jacobi
 */

public class DrawViewDemo
{
    public static void main( String args[] )
    {
        if ( args.length < 1 )
        {
            System.out.println( "usage: DrawViewDemo SourceURL [ connection ]" );
        }
        else
        {
            XComponent xComponent = null;
            try
            {
                String sConnection;
                if ( args.length >= 2 )
                    sConnection = args[ 1 ];
                else
                    sConnection = "uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager";
                XMultiServiceFactory xServiceFactory =
                    Helper.connect( sConnection );

                // suppress Presentation Autopilot when opening the document
                // properties are the same as described for com.sun.star.document.MediaDescriptor
                PropertyValue[] pPropValues = new PropertyValue[ 1 ];
                pPropValues[ 0 ] = new PropertyValue();
                pPropValues[ 0 ].Name = "Silent";
                pPropValues[ 0 ].Value = new Boolean( true );
              
                java.io.File sourceFile = new java.io.File(args[0]);
                StringBuffer sUrl = new StringBuffer("file:///");
                sUrl.append(sourceFile.getCanonicalPath().replace('\\', '/'));
                
                xComponent = Helper.createDocument( xServiceFactory,
                    sUrl.toString(), "_blank", 0, pPropValues );
                XModel xModel =
                    (XModel)UnoRuntime.queryInterface(
                        XModel.class, xComponent );


                // print all available properties of first view
                XViewDataSupplier xViewDataSupplier =
                    (XViewDataSupplier)UnoRuntime.queryInterface(
                        XViewDataSupplier.class, xModel );
                XIndexAccess xIndexAccess = xViewDataSupplier.getViewData();
                if ( xIndexAccess.getCount() != 0 )
                {
                  PropertyValue[] aPropSeq = (PropertyValue[])xIndexAccess.getByIndex( 0 );
                    for( int i = 0; i < aPropSeq.length; i++ )
                    {
                        System.out.println( aPropSeq[ i ].Name + " = " + aPropSeq[ i ].Value );
                    }
                }

                
                // print all properties that are supported by the controller
                // and change into masterpage mode
                XController xController = xModel.getCurrentController();
                XPropertySet xPropSet =
                    (XPropertySet)UnoRuntime.queryInterface(
                        XPropertySet.class, xController );
                XPropertySetInfo xPropSetInfo = xPropSet.getPropertySetInfo();
                Property[] aPropSeq = xPropSetInfo.getProperties();
                for( int i = 0; i < aPropSeq.length; i++ )
                {
                    System.out.println( aPropSeq[ i ].Name );
                }
                xPropSet.setPropertyValue( "IsMasterPageMode", new Boolean( true ) );

            }
            catch( Exception ex )
            {
                System.out.println( ex );
            }
        }
        System.exit( 0 );
    }
}
