import com.sun.star.bridge.XUnoUrlResolver;
import com.sun.star.uno.UnoRuntime;
import com.sun.star.uno.XComponentContext;
import com.sun.star.lang.XMultiComponentFactory;
import com.sun.star.beans.XPropertySet;



/*
 * OpenQuery.java
 *
 * Created on 6. Juli 2002, 10:25
 */

/**
 *
 * @author  dschulten
 */
public class OpenQuery {

    private XComponentContext xRemoteContext = null;
    private XMultiComponentFactory xRemoteServiceManager = null;
    
    /** Creates a new instance of OpenQuery */
    public OpenQuery() {
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        OpenQuery openQuery1 = new OpenQuery();
        try {
            openQuery1.openQuery();
        }
        catch (java.lang.Exception e){
            e.printStackTrace();
        }
        finally {
            System.exit(0);
        }
    }

    protected void openQuery() throws com.sun.star.uno.Exception, java.lang.Exception {
        xRemoteServiceManager = this.getRemoteServiceManager(
        "uno:socket,host=localhost,port=8100;urp;StarOffice.ServiceManager"); 
        
        // first we create our RowSet object and get its XRowSet interface
        Object rowSet = xRemoteServiceManager.createInstanceWithContext(
           "com.sun.star.sdb.RowSet", xRemoteContext);

        com.sun.star.sdbc.XRowSet xRowSet = (com.sun.star.sdbc.XRowSet) 
            UnoRuntime.queryInterface(com.sun.star.sdbc.XRowSet.class, rowSet);

        // set the properties needed to connect to a database
        XPropertySet xProp = (XPropertySet)UnoRuntime.queryInterface(XPropertySet.class, xRowSet);

        // the DataSourceName can be a data source registered with [PRODUCTNAME], among other possibilities
        xProp.setPropertyValue("DataSourceName","Bibliography");

        // the CommandType must be TABLE, QUERY or COMMAND � here we use COMMAND
        xProp.setPropertyValue("CommandType",new Integer(com.sun.star.sdb.CommandType.COMMAND));

        // the Command could be a table or query name or a SQL command, depending on the CommandType
        xProp.setPropertyValue("Command","SELECT IDENTIFIER, AUTHOR FROM biblio ORDER BY IDENTIFIER");

        // if your database requires logon, you can use the properties User and Password
        // xProp.setPropertyValue("User", "JohnDoe");
        // xProp.setPropertyValue("Password", "mysecret");

        xRowSet.execute();

        // prepare the XRow and XColumnLocate interface for column access
        // XRow gets column values
        com.sun.star.sdbc.XRow xRow = (com.sun.star.sdbc.XRow)UnoRuntime.queryInterface(
            com.sun.star.sdbc.XRow.class, xRowSet);
        // XColumnLocate finds columns by name
        com.sun.star.sdbc.XColumnLocate xLoc = (com.sun.star.sdbc.XColumnLocate)
            UnoRuntime.queryInterface(
                com.sun.star.sdbc.XColumnLocate.class, xRowSet);

        // print output header
        System.out.println("Identifier\tAuthor");
        System.out.println("----------\t------");

        // output result rows
        while ( xRowSet != null && xRowSet.next() ) {
            String ident = xRow.getString(xLoc.findColumn("IDENTIFIER"));
            String author = xRow.getString(xLoc.findColumn("AUTHOR"));
            System.out.println(ident + "\t\t" + author);
        }

        // XResultSetUpdate for insertRow handling
        com.sun.star.sdbc.XResultSetUpdate xResultSetUpdate = (com.sun.star.sdbc.XResultSetUpdate)
            UnoRuntime.queryInterface(
                com.sun.star.sdbc.XResultSetUpdate.class, xRowSet);
        
        // XRowUpdate for row updates
        com.sun.star.sdbc.XRowUpdate xRowUpdate = (com.sun.star.sdbc.XRowUpdate)
            UnoRuntime.queryInterface(
                com.sun.star.sdbc.XRowUpdate.class, xRowSet);
        
        // move to insertRow buffer
        xResultSetUpdate.moveToInsertRow();
        
        // edit insertRow buffer
        xRowUpdate.updateString(xLoc.findColumn("IDENTIFIER"), "GOF95");
        xRowUpdate.updateString(xLoc.findColumn("AUTHOR"), "Gamma, Helm, Johnson, Vlissides"); 
        
        // write buffer to database
        xResultSetUpdate.insertRow();
        
        // throw away the row set
        com.sun.star.lang.XComponent xComp = (com.sun.star.lang.XComponent)UnoRuntime.queryInterface(
            com.sun.star.lang.XComponent.class, xRowSet);
        xComp.dispose();
    }        
    
        
    
    protected XMultiComponentFactory getRemoteServiceManager(String unoUrl) throws java.lang.Exception { 
        if (xRemoteContext == null) {
            // First step: create local component context, get local servicemanager and
            // ask it to create a UnoUrlResolver object with an XUnoUrlResolver interface
            XComponentContext xLocalContext =
                com.sun.star.comp.helper.Bootstrap.createInitialComponentContext(null);

            XMultiComponentFactory xLocalServiceManager = xLocalContext.getServiceManager();

            Object urlResolver  = xLocalServiceManager.createInstanceWithContext(
                "com.sun.star.bridge.UnoUrlResolver", xLocalContext );
            // query XUnoUrlResolver interface from urlResolver object
            XUnoUrlResolver xUnoUrlResolver = (XUnoUrlResolver) UnoRuntime.queryInterface( 
                XUnoUrlResolver.class, urlResolver );

            // Second step: use xUrlResolver interface to import the remote StarOffice.ServiceManager,
            // retrieve its property DefaultContext and get the remote servicemanager
            Object initialObject = xUnoUrlResolver.resolve( unoUrl );
            XPropertySet xPropertySet = (XPropertySet)UnoRuntime.queryInterface(
                XPropertySet.class, initialObject);
            Object context = xPropertySet.getPropertyValue("DefaultContext");            
            xRemoteContext = (XComponentContext)UnoRuntime.queryInterface(
                XComponentContext.class, context);
        }
        return xRemoteContext.getServiceManager();
    }    
    
}
