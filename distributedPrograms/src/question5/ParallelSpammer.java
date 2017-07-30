package question5;

import java.sql.*;

public class ParallelSpammer extends Thread {
	static private int threadN = 0;
	private Thread t;
	private Connection c;
	private int n;

	ParallelSpammer(Connection c) {
		this.c = c;
		this.n = ParallelSpammer.threadN++;
	}

	public void run() {
		Statement stmt = null;	
		String insertionQuery = "";
		try {
			stmt = c.createStatement();
			insertionQuery = "INSERT INTO SPAM (NAME) VALUES ('threadNumber:" + n + "');";
			
			synchronized (DB_Spammer.Lock) {
				stmt.executeUpdate(insertionQuery);
			}
			stmt.close();
		} catch (SQLException e) {
			e.printStackTrace();
			System.out.println("Thread " + n + " interrupted.");
			return;
		}
		
		System.out.println("DB Operation Succeeded: " + insertionQuery);
	}

	public void start() {
		System.out.println("Starting " + n);
		if (t == null) {
			t = new Thread(this, Integer.toString(n));
			t.start();
		}
	}
}
