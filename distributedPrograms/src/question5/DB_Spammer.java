package question5;

import java.sql.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class DB_Spammer {
	public static Object Lock = new Object();
	
	private static void createTable(Connection c) {
		Statement stmt = null;
		try {
			stmt = c.createStatement();
			String sql = "CREATE TABLE SPAM " + "(ID INTEGER PRIMARY KEY AUTOINCREMENT,"
					+ " NAME           INTEGER    NOT NULL ) ";
			stmt.executeUpdate(sql);
			stmt.close();
		} catch (Exception e) {
			System.err.println(e.getClass().getName() + ": " + e.getMessage());
			System.exit(0);
		}
		System.out.println("Table created successfully");
	}
	
	private static boolean showTable(Connection c)
	{
		Statement stmt;
		try {
			stmt = c.createStatement();
			ResultSet rs = stmt.executeQuery( "SELECT sql FROM sqlite_master WHERE name = 'SPAM';" );
			
			return rs.next();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
//			e.printStackTrace();
			return false;
		}
	    
	}
	
	private static void selectAllFromTable(Connection c)
	{
		Statement stmt;
		try {
			stmt = c.createStatement();
			ResultSet rs = stmt.executeQuery( "SELECT * FROM SPAM;" );
			
			while ( rs.next() )
			{
				System.out.println("Thread (id, name): (" + rs.getInt("ID") + ", " + rs.getString("NAME") + ")");
			}
			
			stmt.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	    
	}

	public static void main(String args[]) {
		Connection c = null;
		
		try {
			Class.forName("org.sqlite.JDBC");
			c = DriverManager.getConnection("jdbc:sqlite:test.db");
			c.setAutoCommit(false);
			
			if ( !showTable(c) )
			{
				createTable(c);
				System.out.println("Passed Here...");
			}
			ExecutorService executor = Executors.newCachedThreadPool();
			
			for ( int i = 0; i < 10; ++i )
			{
				executor.execute(new ParallelSpammer(c));
			}
			
//			ParallelSpammer P = new ParallelSpammer(c);
//			P.run();
			
			selectAllFromTable(c);
			c.close();
		} catch (Exception e) {
			System.err.println(e.getClass().getName() + ": " + e.getMessage());
			System.exit(0);
		}
		System.out.println("Opened database successfully");

	}
}
