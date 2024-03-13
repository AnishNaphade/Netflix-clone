import java.io.*;

public class assignment3{

public static void main(String[] args) throws IOException {
InputStreamReader isr = new InputStreamReader(System.in);
BufferedReader br = new BufferedReader(isr);
System.out.print("Enter age,name,salary");
int age=Integer.parseInt(br.readLine());
String name= br.readLine();
Double salary=Double.parseDouble(br.readLine());
System.out.println(age);
System.out.println(name);
System.out.print(salary);}

 }