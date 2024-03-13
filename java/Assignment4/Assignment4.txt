import java.io.*;

public class Assignment4 {

public static void main(String[] args){
try{int x[]=new int [7];
x[9]=14;}

catch(Exception e){
System.out.println("exception detected");
System.out.println(e);
 }
try{int b=15;
System.out.print(b/0);}
catch(Exception x){
System.out.println("Exception detected");
System.out.println(x);
}
try{String x=null;
System.out.println(x.length());}
catch(Exception y){
System.out.println("exception detected");
System.out.println(y);
}

try{int num = Integer.parseInt("anish");
System.out.println(num);}
catch(Exception y){
System.out.println("exception detected");
System.out.println(y);

}

try{String x="Anish";
char z=x.charAt(50);}
catch(Exception x){
System.out.println("again exception detected");
System.out.println(x);}

  

}
 }