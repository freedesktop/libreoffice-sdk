/*************************************************************************
 *
 *  $RCSfile: PathSettingsTest.java,v $
 *
 *  $Revision: 1.4 $
 *
 *  last change: $Author: hr $ $Date: 2004-02-02 20:01:55 $
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

import com.sun.star.bridge.XUnoUrlResolver;
import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XComponentContext;
import com.sun.star.lang.XMultiComponentFactory;
import com.sun.star.beans.XPropertySet;
import com.sun.star.beans.PropertyValue;

import com.sun.star.beans.UnknownPropertyException;
/*
 * PathSettingsTest.java
 *
 * Created on 26. March 2003, 08:22
 */

/*
 *
 * @author  Carsten Driesner
 * Provides example code how to access and use the
 * path pathsettings servce.
 */
public class PathSettingsTest extends java.lang.Object {
    
    /*
     * List of pre-defined path variables supported by
     * the path settings service.
     */
    private static String[] predefinedPathProperties = {
        "Addin",
        "AutoCorrect",
        "AutoText",
        "Backup",
        "Basic",
        "Bitmap",
        "Config",
        "Dictionary",
        "Favorite",
        "Filter",
        "Gallery",
        "Graphic",
        "Help",
        "Linguistic",
        "Module",
        "Palette",
        "Plugin",
        "Storage",
        "Temp",
        "Template",
        "UIConfig",
        "UserConfig",
        "UserDictionary",
        "Work"
    };
    
    /*
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        XComponentContext xRemoteContext = null;
        XMultiComponentFactory xRemoteServiceManager = null;
        XPropertySet xPathSettingsService = null;
        
        try {
            // connect
            XComponentContext xLocalContext =
                com.sun.star.comp.helper.Bootstrap.createInitialComponentContext(null);
            XMultiComponentFactory xLocalServiceManager = xLocalContext.getServiceManager();
            Object urlResolver  = xLocalServiceManager.createInstanceWithContext(
                "com.sun.star.bridge.UnoUrlResolver", xLocalContext );
            XUnoUrlResolver xUnoUrlResolver = (XUnoUrlResolver) UnoRuntime.queryInterface( 
                XUnoUrlResolver.class, urlResolver );
            Object initialObject = xUnoUrlResolver.resolve( 
                "uno:socket,host=localhost,port=2083;urp;StarOffice.ServiceManager" );
            XPropertySet xPropertySet = (XPropertySet)UnoRuntime.queryInterface(
                XPropertySet.class, initialObject);
            Object context = xPropertySet.getPropertyValue("DefaultContext");            
            xRemoteContext = (XComponentContext)UnoRuntime.queryInterface(
                XComponentContext.class, context);
            xRemoteServiceManager = xRemoteContext.getServiceManager();
            
            Object pathSubst = xRemoteServiceManager.createInstanceWithContext(
                "com.sun.star.comp.framework.PathSettings", xRemoteContext );
            xPathSettingsService = (XPropertySet)UnoRuntime.queryInterface(
                XPropertySet.class, pathSubst);
            
            /* Work with path settings */
            workWithPathSettings( xPathSettingsService );
        }
        catch (java.lang.Exception e){
            e.printStackTrace();
        }
        finally {
            System.exit(0);
        }
    }

    /*
     * Retrieve and set path properties from path settings service
     * @param xPathSettingsService the path settings service
     */
    public static void workWithPathSettings( XPropertySet xPathSettingsService )
    {
        if ( xPathSettingsService != null ) {
            for ( int i=0; i<predefinedPathProperties.length; i++ ) {
                try {
                        /* Retrieve values for path properties from path settings service*/ 
                        Object aValue = xPathSettingsService.getPropertyValue( 
                                            predefinedPathProperties[i] );
                        
                        // getPropertyValue returns an Object, you have to cast it to type that you need 
                        String aPath = (String)aValue;
                        System.out.println( "Property="+ predefinedPathProperties[i] + 
                                            " Path=" + aPath );
                }
                catch ( com.sun.star.beans.UnknownPropertyException e) {
                    System.out.println( "UnknownPropertyException has been thrown accessing "+predefinedPathProperties[i]);
                }
                catch ( com.sun.star.lang.WrappedTargetException e ) {
                    System.out.println( "WrappedTargetException has been thrown accessing "+predefinedPathProperties[i]);
                }
            }
            
            // Try to modfiy the work path property. After running this example
            // you should see the new value of "My Documents" in the path options 
            // tab page, accessible via "Tools - Options - [Star|Open]Office - Paths". 
            // If you want to revert the changes, you can also do it with the path tab page.
            try {
                xPathSettingsService.setPropertyValue( "Work", "$(temp)" );
                String aValue = (String)xPathSettingsService.getPropertyValue( "Work" );
                System.out.println( "The work path should now be " + aValue );
            }
            catch ( com.sun.star.beans.UnknownPropertyException e) {
                System.out.println( "UnknownPropertyException has been thrown accessing PathSettings service");
            }
            catch ( com.sun.star.lang.WrappedTargetException e ) {
                System.out.println( "WrappedTargetException has been thrown accessing PathSettings service");
            }
            catch ( com.sun.star.beans.PropertyVetoException e ) {
                System.out.println( "PropertyVetoException has been thrown accessing PathSettings service");
            }
            catch ( com.sun.star.lang.IllegalArgumentException e ) {
                System.out.println( "IllegalArgumentException has been thrown accessing PathSettings service");
            }
        }
    }
}
