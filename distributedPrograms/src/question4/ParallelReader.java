package question4;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Iterator;
import java.util.stream.Stream;

public class ParallelReader extends Thread {
	static private int threadN = 0;
	private Thread t;
	private String path;
	private int n;

	ParallelReader(String path) {
		this.path = path;
		this.n = ParallelReader.threadN++;
		System.out.println("Creating " + path);
	}

	public void run() {
		Path realpath = FileSystems.getDefault().getPath("", path);
		
		System.out.println("Running " + threadN + " at " + path.toString());
		
		try {
			Stream<String> file = Files.lines(realpath);
			Iterator<String> it = file.iterator();
			while (it.hasNext()) {
				System.out.println (it.next());
	            Thread.sleep(2000);
			}
			file.close();
		} catch (InterruptedException e) {
			System.out.println("Thread " + n + " interrupted.");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("Thread " + n + " exiting.");
	}

	public void start() {
		System.out.println("Starting " + n);
		if (t == null) {
			t = new Thread(this, Integer.toString(n));
			t.start();
		}
	}
}
