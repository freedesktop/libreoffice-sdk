/*************************************************************************
 *
 *  $RCSfile: ControlAndSelectDemo.java,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: hr $ $Date: 2004-02-02 19:52:50 $
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

// application specific classes
import com.sun.star.drawing.*;

// XModel, XController
import com.sun.star.frame.*;

// Point, Size
import com.sun.star.awt.*;

//
import com.sun.star.view.*;


// __________ Implementation __________

/** ControlAndSelectDemo
    @author Sven Jacobi

   A (GroupBox) ControlShape will be created.
   Finally the ControlShape will be inserted into a selection.
*/

public class ControlAndSelectDemo
{
    public static void main( String args[] )
    {
        XComponent xComponent = null;
        try
        {
            String sConnection;
            if ( args.length >= 1 )
                sConnection = args[ 0 ];
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

            xComponent = Helper.createDocument( xServiceFactory,
                "private:factory/sdraw", "_blank", 0, pPropValues );

            XMultiServiceFactory xFactory =
                (XMultiServiceFactory )UnoRuntime.queryInterface(
                    XMultiServiceFactory.class, xComponent );
        
            XDrawPagesSupplier xDrawPagesSupplier =
                (XDrawPagesSupplier)UnoRuntime.queryInterface(
                    XDrawPagesSupplier.class, xComponent );
            XDrawPages xDrawPages = xDrawPagesSupplier.getDrawPages();
            XDrawPage xDrawPage = (XDrawPage)UnoRuntime.queryInterface(
                XDrawPage.class, xDrawPages.getByIndex( 0 ));
            XShapes xShapes = (XShapes)UnoRuntime.queryInterface( XShapes.class, xDrawPage );


            // create and insert the ControlShape
            Object xObj = xFactory.createInstance( "com.sun.star.drawing.ControlShape" );
            XShape xShape = (XShape)UnoRuntime.queryInterface( XShape.class, xObj );
            xShape.setPosition( new Point( 1000, 1000 ) );
            xShape.setSize( new Size( 2000, 2000 ) );
            xShapes.add( xShape );

            // create and set the control
            XControlModel xControlModel = (XControlModel)UnoRuntime.queryInterface( XControlModel.class,
                xFactory.createInstance( "com.sun.star.form.component.GroupBox" ) );
            XControlShape xControlShape = (XControlShape)UnoRuntime.queryInterface( XControlShape.class, xShape );
            xControlShape.setControl( xControlModel );


            // the following code will demonstrate how to
            // make a selection that contains our new created ControlShape
            XModel xModel = (XModel)UnoRuntime.queryInterface( XModel.class, xComponent );
            XController xController = xModel.getCurrentController();
            XSelectionSupplier xSelectionSupplier =(XSelectionSupplier)
                UnoRuntime.queryInterface( XSelectionSupplier.class, xController );
            // take care to use the global service factory only and not the one that is
            // provided by the component if you create the ShapeColletion
            XShapes xSelection = (XShapes)UnoRuntime.queryInterface( XShapes.class,
                xServiceFactory.createInstance( "com.sun.star.drawing.ShapeCollection" ) );
            xSelection.add( xShape );
            xSelectionSupplier.select( xSelection );
        }
        catch( java.lang.Exception ex )
        {
            System.out.println( ex );
        }
        System.exit( 0 );
    }
}
