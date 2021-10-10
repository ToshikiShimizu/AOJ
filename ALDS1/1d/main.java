import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
	    int n = sc.nextInt();
	    int r = sc.nextInt();
	    
	    int max = -1000000000;
	    int min = r;
	    
	    for(int i = 1; i < n; i++) {
	        int rate = sc.nextInt();
            max = Math.max(max, rate - min);
            min = Math.min(min, rate);
        }
        
        System.out.println(max);
        
    }
}

