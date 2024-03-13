
import java.util.Scanner;
import java.util.*;
public class prime {
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = 16;
        
        if(n == 1) {
            System.out.println("prime");
            return;
        }
        else{
        
        for(int i=2;i<n;i++) {
            if(n % i == 0) {
                System.out.println("non prime");
                return;
            }
        }
    }
        
        System.out.println("YES");
    }
}
